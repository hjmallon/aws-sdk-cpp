﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/outposts/Outposts_EXPORTS.h>
#include <aws/outposts/OutpostsErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/outposts/model/CreateOrderResult.h>
#include <aws/outposts/model/CreateOutpostResult.h>
#include <aws/outposts/model/DeleteOutpostResult.h>
#include <aws/outposts/model/DeleteSiteResult.h>
#include <aws/outposts/model/GetOutpostResult.h>
#include <aws/outposts/model/GetOutpostInstanceTypesResult.h>
#include <aws/outposts/model/ListOutpostsResult.h>
#include <aws/outposts/model/ListSitesResult.h>
#include <aws/outposts/model/ListTagsForResourceResult.h>
#include <aws/outposts/model/TagResourceResult.h>
#include <aws/outposts/model/UntagResourceResult.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <future>
#include <functional>

namespace Aws
{

namespace Http
{
  class HttpClient;
  class HttpClientFactory;
} // namespace Http

namespace Utils
{
  template< typename R, typename E> class Outcome;
namespace Threading
{
  class Executor;
} // namespace Threading
} // namespace Utils

namespace Auth
{
  class AWSCredentials;
  class AWSCredentialsProvider;
} // namespace Auth

namespace Client
{
  class RetryStrategy;
} // namespace Client

namespace Outposts
{

namespace Model
{
        class CreateOrderRequest;
        class CreateOutpostRequest;
        class DeleteOutpostRequest;
        class DeleteSiteRequest;
        class GetOutpostRequest;
        class GetOutpostInstanceTypesRequest;
        class ListOutpostsRequest;
        class ListSitesRequest;
        class ListTagsForResourceRequest;
        class TagResourceRequest;
        class UntagResourceRequest;

        typedef Aws::Utils::Outcome<CreateOrderResult, OutpostsError> CreateOrderOutcome;
        typedef Aws::Utils::Outcome<CreateOutpostResult, OutpostsError> CreateOutpostOutcome;
        typedef Aws::Utils::Outcome<DeleteOutpostResult, OutpostsError> DeleteOutpostOutcome;
        typedef Aws::Utils::Outcome<DeleteSiteResult, OutpostsError> DeleteSiteOutcome;
        typedef Aws::Utils::Outcome<GetOutpostResult, OutpostsError> GetOutpostOutcome;
        typedef Aws::Utils::Outcome<GetOutpostInstanceTypesResult, OutpostsError> GetOutpostInstanceTypesOutcome;
        typedef Aws::Utils::Outcome<ListOutpostsResult, OutpostsError> ListOutpostsOutcome;
        typedef Aws::Utils::Outcome<ListSitesResult, OutpostsError> ListSitesOutcome;
        typedef Aws::Utils::Outcome<ListTagsForResourceResult, OutpostsError> ListTagsForResourceOutcome;
        typedef Aws::Utils::Outcome<TagResourceResult, OutpostsError> TagResourceOutcome;
        typedef Aws::Utils::Outcome<UntagResourceResult, OutpostsError> UntagResourceOutcome;

        typedef std::future<CreateOrderOutcome> CreateOrderOutcomeCallable;
        typedef std::future<CreateOutpostOutcome> CreateOutpostOutcomeCallable;
        typedef std::future<DeleteOutpostOutcome> DeleteOutpostOutcomeCallable;
        typedef std::future<DeleteSiteOutcome> DeleteSiteOutcomeCallable;
        typedef std::future<GetOutpostOutcome> GetOutpostOutcomeCallable;
        typedef std::future<GetOutpostInstanceTypesOutcome> GetOutpostInstanceTypesOutcomeCallable;
        typedef std::future<ListOutpostsOutcome> ListOutpostsOutcomeCallable;
        typedef std::future<ListSitesOutcome> ListSitesOutcomeCallable;
        typedef std::future<ListTagsForResourceOutcome> ListTagsForResourceOutcomeCallable;
        typedef std::future<TagResourceOutcome> TagResourceOutcomeCallable;
        typedef std::future<UntagResourceOutcome> UntagResourceOutcomeCallable;
} // namespace Model

  class OutpostsClient;

    typedef std::function<void(const OutpostsClient*, const Model::CreateOrderRequest&, const Model::CreateOrderOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateOrderResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::CreateOutpostRequest&, const Model::CreateOutpostOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateOutpostResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::DeleteOutpostRequest&, const Model::DeleteOutpostOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteOutpostResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::DeleteSiteRequest&, const Model::DeleteSiteOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteSiteResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::GetOutpostRequest&, const Model::GetOutpostOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetOutpostResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::GetOutpostInstanceTypesRequest&, const Model::GetOutpostInstanceTypesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetOutpostInstanceTypesResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::ListOutpostsRequest&, const Model::ListOutpostsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListOutpostsResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::ListSitesRequest&, const Model::ListSitesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListSitesResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::ListTagsForResourceRequest&, const Model::ListTagsForResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListTagsForResourceResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::TagResourceRequest&, const Model::TagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TagResourceResponseReceivedHandler;
    typedef std::function<void(const OutpostsClient*, const Model::UntagResourceRequest&, const Model::UntagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UntagResourceResponseReceivedHandler;

  /**
   * <p>AWS Outposts is a fully managed service that extends AWS infrastructure,
   * APIs, and tools to customer premises. By providing local access to AWS managed
   * infrastructure, AWS Outposts enables customers to build and run applications on
   * premises using the same programming interfaces as in AWS Regions, while using
   * local compute and storage resources for lower latency and local data processing
   * needs.</p>
   */
  class AWS_OUTPOSTS_API OutpostsClient : public Aws::Client::AWSJsonClient
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        OutpostsClient(const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        OutpostsClient(const Aws::Auth::AWSCredentials& credentials, const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        OutpostsClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
            const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

        virtual ~OutpostsClient();


        /**
         * <p>Creates an order for an Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOrder">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateOrderOutcome CreateOrder(const Model::CreateOrderRequest& request) const;

        /**
         * <p>Creates an order for an Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOrder">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateOrderOutcomeCallable CreateOrderCallable(const Model::CreateOrderRequest& request) const;

        /**
         * <p>Creates an order for an Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOrder">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateOrderAsync(const Model::CreateOrderRequest& request, const CreateOrderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates an Outpost.</p> <p>You can specify <code>AvailabilityZone</code> or
         * <code>AvailabilityZoneId</code>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOutpost">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateOutpostOutcome CreateOutpost(const Model::CreateOutpostRequest& request) const;

        /**
         * <p>Creates an Outpost.</p> <p>You can specify <code>AvailabilityZone</code> or
         * <code>AvailabilityZoneId</code>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOutpost">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateOutpostOutcomeCallable CreateOutpostCallable(const Model::CreateOutpostRequest& request) const;

        /**
         * <p>Creates an Outpost.</p> <p>You can specify <code>AvailabilityZone</code> or
         * <code>AvailabilityZoneId</code>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/CreateOutpost">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateOutpostAsync(const Model::CreateOutpostRequest& request, const CreateOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes the Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteOutpost">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteOutpostOutcome DeleteOutpost(const Model::DeleteOutpostRequest& request) const;

        /**
         * <p>Deletes the Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteOutpost">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteOutpostOutcomeCallable DeleteOutpostCallable(const Model::DeleteOutpostRequest& request) const;

        /**
         * <p>Deletes the Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteOutpost">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteOutpostAsync(const Model::DeleteOutpostRequest& request, const DeleteOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes the site.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteSite">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteSiteOutcome DeleteSite(const Model::DeleteSiteRequest& request) const;

        /**
         * <p>Deletes the site.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteSite">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteSiteOutcomeCallable DeleteSiteCallable(const Model::DeleteSiteRequest& request) const;

        /**
         * <p>Deletes the site.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/DeleteSite">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteSiteAsync(const Model::DeleteSiteRequest& request, const DeleteSiteResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Gets information about the specified Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpost">AWS
         * API Reference</a></p>
         */
        virtual Model::GetOutpostOutcome GetOutpost(const Model::GetOutpostRequest& request) const;

        /**
         * <p>Gets information about the specified Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpost">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetOutpostOutcomeCallable GetOutpostCallable(const Model::GetOutpostRequest& request) const;

        /**
         * <p>Gets information about the specified Outpost.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpost">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetOutpostAsync(const Model::GetOutpostRequest& request, const GetOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists the instance types for the specified Outpost.</p><p><h3>See Also:</h3> 
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpostInstanceTypes">AWS
         * API Reference</a></p>
         */
        virtual Model::GetOutpostInstanceTypesOutcome GetOutpostInstanceTypes(const Model::GetOutpostInstanceTypesRequest& request) const;

        /**
         * <p>Lists the instance types for the specified Outpost.</p><p><h3>See Also:</h3> 
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpostInstanceTypes">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetOutpostInstanceTypesOutcomeCallable GetOutpostInstanceTypesCallable(const Model::GetOutpostInstanceTypesRequest& request) const;

        /**
         * <p>Lists the instance types for the specified Outpost.</p><p><h3>See Also:</h3> 
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/GetOutpostInstanceTypes">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetOutpostInstanceTypesAsync(const Model::GetOutpostInstanceTypesRequest& request, const GetOutpostInstanceTypesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Create a list of the Outposts for your AWS account. Add filters to your
         * request to return a more specific list of results. Use filters to match an
         * Outpost lifecycle status, Availibility Zone (<code>us-east-1a</code>), and AZ ID
         * (<code>use1-az1</code>). </p> <p>If you specify multiple filters, the filters
         * are joined with an <code>AND</code>, and the request returns only results that
         * match all of the specified filters.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListOutposts">AWS
         * API Reference</a></p>
         */
        virtual Model::ListOutpostsOutcome ListOutposts(const Model::ListOutpostsRequest& request) const;

        /**
         * <p>Create a list of the Outposts for your AWS account. Add filters to your
         * request to return a more specific list of results. Use filters to match an
         * Outpost lifecycle status, Availibility Zone (<code>us-east-1a</code>), and AZ ID
         * (<code>use1-az1</code>). </p> <p>If you specify multiple filters, the filters
         * are joined with an <code>AND</code>, and the request returns only results that
         * match all of the specified filters.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListOutposts">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListOutpostsOutcomeCallable ListOutpostsCallable(const Model::ListOutpostsRequest& request) const;

        /**
         * <p>Create a list of the Outposts for your AWS account. Add filters to your
         * request to return a more specific list of results. Use filters to match an
         * Outpost lifecycle status, Availibility Zone (<code>us-east-1a</code>), and AZ ID
         * (<code>use1-az1</code>). </p> <p>If you specify multiple filters, the filters
         * are joined with an <code>AND</code>, and the request returns only results that
         * match all of the specified filters.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListOutposts">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListOutpostsAsync(const Model::ListOutpostsRequest& request, const ListOutpostsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists the sites for the specified AWS account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListSites">AWS
         * API Reference</a></p>
         */
        virtual Model::ListSitesOutcome ListSites(const Model::ListSitesRequest& request) const;

        /**
         * <p>Lists the sites for the specified AWS account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListSites">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListSitesOutcomeCallable ListSitesCallable(const Model::ListSitesRequest& request) const;

        /**
         * <p>Lists the sites for the specified AWS account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListSites">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListSitesAsync(const Model::ListSitesRequest& request, const ListSitesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists the tags for the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListTagsForResource">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTagsForResourceOutcome ListTagsForResource(const Model::ListTagsForResourceRequest& request) const;

        /**
         * <p>Lists the tags for the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListTagsForResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListTagsForResourceOutcomeCallable ListTagsForResourceCallable(const Model::ListTagsForResourceRequest& request) const;

        /**
         * <p>Lists the tags for the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/ListTagsForResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListTagsForResourceAsync(const Model::ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Adds tags to the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/TagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::TagResourceOutcome TagResource(const Model::TagResourceRequest& request) const;

        /**
         * <p>Adds tags to the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/TagResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::TagResourceOutcomeCallable TagResourceCallable(const Model::TagResourceRequest& request) const;

        /**
         * <p>Adds tags to the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/TagResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void TagResourceAsync(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Removes tags from the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/UntagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::UntagResourceOutcome UntagResource(const Model::UntagResourceRequest& request) const;

        /**
         * <p>Removes tags from the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/UntagResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UntagResourceOutcomeCallable UntagResourceCallable(const Model::UntagResourceRequest& request) const;

        /**
         * <p>Removes tags from the specified resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/outposts-2019-12-03/UntagResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UntagResourceAsync(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


      void OverrideEndpoint(const Aws::String& endpoint);
    private:
      void init(const Aws::Client::ClientConfiguration& clientConfiguration);
        void CreateOrderAsyncHelper(const Model::CreateOrderRequest& request, const CreateOrderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateOutpostAsyncHelper(const Model::CreateOutpostRequest& request, const CreateOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteOutpostAsyncHelper(const Model::DeleteOutpostRequest& request, const DeleteOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteSiteAsyncHelper(const Model::DeleteSiteRequest& request, const DeleteSiteResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetOutpostAsyncHelper(const Model::GetOutpostRequest& request, const GetOutpostResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetOutpostInstanceTypesAsyncHelper(const Model::GetOutpostInstanceTypesRequest& request, const GetOutpostInstanceTypesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListOutpostsAsyncHelper(const Model::ListOutpostsRequest& request, const ListOutpostsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListSitesAsyncHelper(const Model::ListSitesRequest& request, const ListSitesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListTagsForResourceAsyncHelper(const Model::ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void TagResourceAsyncHelper(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UntagResourceAsyncHelper(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

      Aws::String m_uri;
      Aws::String m_configScheme;
      std::shared_ptr<Aws::Utils::Threading::Executor> m_executor;
  };

} // namespace Outposts
} // namespace Aws
