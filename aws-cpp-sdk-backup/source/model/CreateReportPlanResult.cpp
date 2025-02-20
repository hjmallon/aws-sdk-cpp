﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/backup/model/CreateReportPlanResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Backup::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

CreateReportPlanResult::CreateReportPlanResult()
{
}

CreateReportPlanResult::CreateReportPlanResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

CreateReportPlanResult& CreateReportPlanResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ReportPlanName"))
  {
    m_reportPlanName = jsonValue.GetString("ReportPlanName");

  }

  if(jsonValue.ValueExists("ReportPlanArn"))
  {
    m_reportPlanArn = jsonValue.GetString("ReportPlanArn");

  }



  return *this;
}
