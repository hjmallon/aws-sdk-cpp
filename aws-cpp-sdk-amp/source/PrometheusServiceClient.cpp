﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/Outcome.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/threading/Executor.h>
#include <aws/core/utils/DNS.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <aws/amp/PrometheusServiceClient.h>
#include <aws/amp/PrometheusServiceEndpoint.h>
#include <aws/amp/PrometheusServiceErrorMarshaller.h>
#include <aws/amp/model/CreateWorkspaceRequest.h>
#include <aws/amp/model/DeleteWorkspaceRequest.h>
#include <aws/amp/model/DescribeWorkspaceRequest.h>
#include <aws/amp/model/ListTagsForResourceRequest.h>
#include <aws/amp/model/ListWorkspacesRequest.h>
#include <aws/amp/model/TagResourceRequest.h>
#include <aws/amp/model/UntagResourceRequest.h>
#include <aws/amp/model/UpdateWorkspaceAliasRequest.h>

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Client;
using namespace Aws::PrometheusService;
using namespace Aws::PrometheusService::Model;
using namespace Aws::Http;
using namespace Aws::Utils::Json;

static const char* SERVICE_NAME = "aps";
static const char* ALLOCATION_TAG = "PrometheusServiceClient";


PrometheusServiceClient::PrometheusServiceClient(const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<DefaultAWSCredentialsProviderChain>(ALLOCATION_TAG),
        SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<PrometheusServiceErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

PrometheusServiceClient::PrometheusServiceClient(const AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<SimpleAWSCredentialsProvider>(ALLOCATION_TAG, credentials),
         SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<PrometheusServiceErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

PrometheusServiceClient::PrometheusServiceClient(const std::shared_ptr<AWSCredentialsProvider>& credentialsProvider,
  const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, credentialsProvider,
         SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<PrometheusServiceErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

PrometheusServiceClient::~PrometheusServiceClient()
{
}

void PrometheusServiceClient::init(const Client::ClientConfiguration& config)
{
  SetServiceClientName("amp");
  m_configScheme = SchemeMapper::ToString(config.scheme);
  if (config.endpointOverride.empty())
  {
      m_uri = m_configScheme + "://" + PrometheusServiceEndpoint::ForRegion(config.region, config.useDualStack);
  }
  else
  {
      OverrideEndpoint(config.endpointOverride);
  }
}

void PrometheusServiceClient::OverrideEndpoint(const Aws::String& endpoint)
{
  if (endpoint.compare(0, 7, "http://") == 0 || endpoint.compare(0, 8, "https://") == 0)
  {
      m_uri = endpoint;
  }
  else
  {
      m_uri = m_configScheme + "://" + endpoint;
  }
}

CreateWorkspaceOutcome PrometheusServiceClient::CreateWorkspace(const CreateWorkspaceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/workspaces");
  return CreateWorkspaceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateWorkspaceOutcomeCallable PrometheusServiceClient::CreateWorkspaceCallable(const CreateWorkspaceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateWorkspaceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateWorkspace(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::CreateWorkspaceAsync(const CreateWorkspaceRequest& request, const CreateWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreateWorkspaceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::CreateWorkspaceAsyncHelper(const CreateWorkspaceRequest& request, const CreateWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreateWorkspace(request), context);
}

DeleteWorkspaceOutcome PrometheusServiceClient::DeleteWorkspace(const DeleteWorkspaceRequest& request) const
{
  if (!request.WorkspaceIdHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DeleteWorkspace", "Required field: WorkspaceId, is not set");
    return DeleteWorkspaceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [WorkspaceId]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/workspaces/");
  uri.AddPathSegment(request.GetWorkspaceId());
  return DeleteWorkspaceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_DELETE, Aws::Auth::SIGV4_SIGNER));
}

DeleteWorkspaceOutcomeCallable PrometheusServiceClient::DeleteWorkspaceCallable(const DeleteWorkspaceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteWorkspaceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteWorkspace(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::DeleteWorkspaceAsync(const DeleteWorkspaceRequest& request, const DeleteWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteWorkspaceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::DeleteWorkspaceAsyncHelper(const DeleteWorkspaceRequest& request, const DeleteWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteWorkspace(request), context);
}

DescribeWorkspaceOutcome PrometheusServiceClient::DescribeWorkspace(const DescribeWorkspaceRequest& request) const
{
  if (!request.WorkspaceIdHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DescribeWorkspace", "Required field: WorkspaceId, is not set");
    return DescribeWorkspaceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [WorkspaceId]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/workspaces/");
  uri.AddPathSegment(request.GetWorkspaceId());
  return DescribeWorkspaceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

DescribeWorkspaceOutcomeCallable PrometheusServiceClient::DescribeWorkspaceCallable(const DescribeWorkspaceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeWorkspaceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeWorkspace(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::DescribeWorkspaceAsync(const DescribeWorkspaceRequest& request, const DescribeWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeWorkspaceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::DescribeWorkspaceAsyncHelper(const DescribeWorkspaceRequest& request, const DescribeWorkspaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeWorkspace(request), context);
}

ListTagsForResourceOutcome PrometheusServiceClient::ListTagsForResource(const ListTagsForResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("ListTagsForResource", "Required field: ResourceArn, is not set");
    return ListTagsForResourceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/tags/");
  uri.AddPathSegment(request.GetResourceArn());
  return ListTagsForResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListTagsForResourceOutcomeCallable PrometheusServiceClient::ListTagsForResourceCallable(const ListTagsForResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListTagsForResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListTagsForResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::ListTagsForResourceAsync(const ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListTagsForResourceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::ListTagsForResourceAsyncHelper(const ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListTagsForResource(request), context);
}

ListWorkspacesOutcome PrometheusServiceClient::ListWorkspaces(const ListWorkspacesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/workspaces");
  return ListWorkspacesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListWorkspacesOutcomeCallable PrometheusServiceClient::ListWorkspacesCallable(const ListWorkspacesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListWorkspacesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListWorkspaces(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::ListWorkspacesAsync(const ListWorkspacesRequest& request, const ListWorkspacesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListWorkspacesAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::ListWorkspacesAsyncHelper(const ListWorkspacesRequest& request, const ListWorkspacesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListWorkspaces(request), context);
}

TagResourceOutcome PrometheusServiceClient::TagResource(const TagResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("TagResource", "Required field: ResourceArn, is not set");
    return TagResourceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/tags/");
  uri.AddPathSegment(request.GetResourceArn());
  return TagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

TagResourceOutcomeCallable PrometheusServiceClient::TagResourceCallable(const TagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< TagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->TagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::TagResourceAsync(const TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->TagResourceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::TagResourceAsyncHelper(const TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, TagResource(request), context);
}

UntagResourceOutcome PrometheusServiceClient::UntagResource(const UntagResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UntagResource", "Required field: ResourceArn, is not set");
    return UntagResourceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  if (!request.TagKeysHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UntagResource", "Required field: TagKeys, is not set");
    return UntagResourceOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [TagKeys]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/tags/");
  uri.AddPathSegment(request.GetResourceArn());
  return UntagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_DELETE, Aws::Auth::SIGV4_SIGNER));
}

UntagResourceOutcomeCallable PrometheusServiceClient::UntagResourceCallable(const UntagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UntagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UntagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::UntagResourceAsync(const UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->UntagResourceAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::UntagResourceAsyncHelper(const UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, UntagResource(request), context);
}

UpdateWorkspaceAliasOutcome PrometheusServiceClient::UpdateWorkspaceAlias(const UpdateWorkspaceAliasRequest& request) const
{
  if (!request.WorkspaceIdHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UpdateWorkspaceAlias", "Required field: WorkspaceId, is not set");
    return UpdateWorkspaceAliasOutcome(Aws::Client::AWSError<PrometheusServiceErrors>(PrometheusServiceErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [WorkspaceId]", false));
  }
  Aws::Http::URI uri = m_uri;
  uri.AddPathSegments("/workspaces/");
  uri.AddPathSegment(request.GetWorkspaceId());
  uri.AddPathSegments("/alias");
  return UpdateWorkspaceAliasOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateWorkspaceAliasOutcomeCallable PrometheusServiceClient::UpdateWorkspaceAliasCallable(const UpdateWorkspaceAliasRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateWorkspaceAliasOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateWorkspaceAlias(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void PrometheusServiceClient::UpdateWorkspaceAliasAsync(const UpdateWorkspaceAliasRequest& request, const UpdateWorkspaceAliasResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->UpdateWorkspaceAliasAsyncHelper( request, handler, context ); } );
}

void PrometheusServiceClient::UpdateWorkspaceAliasAsyncHelper(const UpdateWorkspaceAliasRequest& request, const UpdateWorkspaceAliasResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, UpdateWorkspaceAlias(request), context);
}

