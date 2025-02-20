﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/appsync/AppSync_EXPORTS.h>
#include <aws/appsync/model/FieldLogLevel.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace AppSync
{
namespace Model
{

  /**
   * <p>The CloudWatch Logs configuration.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/appsync-2017-07-25/LogConfig">AWS
   * API Reference</a></p>
   */
  class AWS_APPSYNC_API LogConfig
  {
  public:
    LogConfig();
    LogConfig(Aws::Utils::Json::JsonView jsonValue);
    LogConfig& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline const FieldLogLevel& GetFieldLogLevel() const{ return m_fieldLogLevel; }

    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline bool FieldLogLevelHasBeenSet() const { return m_fieldLogLevelHasBeenSet; }

    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline void SetFieldLogLevel(const FieldLogLevel& value) { m_fieldLogLevelHasBeenSet = true; m_fieldLogLevel = value; }

    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline void SetFieldLogLevel(FieldLogLevel&& value) { m_fieldLogLevelHasBeenSet = true; m_fieldLogLevel = std::move(value); }

    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline LogConfig& WithFieldLogLevel(const FieldLogLevel& value) { SetFieldLogLevel(value); return *this;}

    /**
     * <p>The field logging level. Values can be NONE, ERROR, or ALL. </p> <ul> <li>
     * <p> <b>NONE</b>: No field-level logs are captured.</p> </li> <li> <p>
     * <b>ERROR</b>: Logs the following information only for the fields that are in
     * error:</p> <ul> <li> <p>The error section in the server response.</p> </li> <li>
     * <p>Field-level errors.</p> </li> <li> <p>The generated request/response
     * functions that got resolved for error fields.</p> </li> </ul> </li> <li> <p>
     * <b>ALL</b>: The following information is logged for all fields in the query:</p>
     * <ul> <li> <p>Field-level tracing information.</p> </li> <li> <p>The generated
     * request/response functions that got resolved for each field.</p> </li> </ul>
     * </li> </ul>
     */
    inline LogConfig& WithFieldLogLevel(FieldLogLevel&& value) { SetFieldLogLevel(std::move(value)); return *this;}


    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline const Aws::String& GetCloudWatchLogsRoleArn() const{ return m_cloudWatchLogsRoleArn; }

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline bool CloudWatchLogsRoleArnHasBeenSet() const { return m_cloudWatchLogsRoleArnHasBeenSet; }

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline void SetCloudWatchLogsRoleArn(const Aws::String& value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn = value; }

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline void SetCloudWatchLogsRoleArn(Aws::String&& value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn = std::move(value); }

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline void SetCloudWatchLogsRoleArn(const char* value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn.assign(value); }

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline LogConfig& WithCloudWatchLogsRoleArn(const Aws::String& value) { SetCloudWatchLogsRoleArn(value); return *this;}

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline LogConfig& WithCloudWatchLogsRoleArn(Aws::String&& value) { SetCloudWatchLogsRoleArn(std::move(value)); return *this;}

    /**
     * <p>The service role that AppSync will assume to publish to Amazon CloudWatch
     * logs in your account. </p>
     */
    inline LogConfig& WithCloudWatchLogsRoleArn(const char* value) { SetCloudWatchLogsRoleArn(value); return *this;}


    /**
     * <p>Set to TRUE to exclude sections that contain information such as headers,
     * context, and evaluated mapping templates, regardless of logging level.</p>
     */
    inline bool GetExcludeVerboseContent() const{ return m_excludeVerboseContent; }

    /**
     * <p>Set to TRUE to exclude sections that contain information such as headers,
     * context, and evaluated mapping templates, regardless of logging level.</p>
     */
    inline bool ExcludeVerboseContentHasBeenSet() const { return m_excludeVerboseContentHasBeenSet; }

    /**
     * <p>Set to TRUE to exclude sections that contain information such as headers,
     * context, and evaluated mapping templates, regardless of logging level.</p>
     */
    inline void SetExcludeVerboseContent(bool value) { m_excludeVerboseContentHasBeenSet = true; m_excludeVerboseContent = value; }

    /**
     * <p>Set to TRUE to exclude sections that contain information such as headers,
     * context, and evaluated mapping templates, regardless of logging level.</p>
     */
    inline LogConfig& WithExcludeVerboseContent(bool value) { SetExcludeVerboseContent(value); return *this;}

  private:

    FieldLogLevel m_fieldLogLevel;
    bool m_fieldLogLevelHasBeenSet;

    Aws::String m_cloudWatchLogsRoleArn;
    bool m_cloudWatchLogsRoleArnHasBeenSet;

    bool m_excludeVerboseContent;
    bool m_excludeVerboseContentHasBeenSet;
  };

} // namespace Model
} // namespace AppSync
} // namespace Aws
