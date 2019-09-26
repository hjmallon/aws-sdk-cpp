﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/codepipeline/model/TriggerType.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace CodePipeline
  {
    namespace Model
    {
      namespace TriggerTypeMapper
      {

        static const int CreatePipeline_HASH = HashingUtils::HashString("CreatePipeline");
        static const int StartPipelineExecution_HASH = HashingUtils::HashString("StartPipelineExecution");
        static const int PollForSourceChanges_HASH = HashingUtils::HashString("PollForSourceChanges");
        static const int Webhook_HASH = HashingUtils::HashString("Webhook");
        static const int CloudWatchEvent_HASH = HashingUtils::HashString("CloudWatchEvent");
        static const int PutActionRevision_HASH = HashingUtils::HashString("PutActionRevision");


        TriggerType GetTriggerTypeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == CreatePipeline_HASH)
          {
            return TriggerType::CreatePipeline;
          }
          else if (hashCode == StartPipelineExecution_HASH)
          {
            return TriggerType::StartPipelineExecution;
          }
          else if (hashCode == PollForSourceChanges_HASH)
          {
            return TriggerType::PollForSourceChanges;
          }
          else if (hashCode == Webhook_HASH)
          {
            return TriggerType::Webhook;
          }
          else if (hashCode == CloudWatchEvent_HASH)
          {
            return TriggerType::CloudWatchEvent;
          }
          else if (hashCode == PutActionRevision_HASH)
          {
            return TriggerType::PutActionRevision;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<TriggerType>(hashCode);
          }

          return TriggerType::NOT_SET;
        }

        Aws::String GetNameForTriggerType(TriggerType enumValue)
        {
          switch(enumValue)
          {
          case TriggerType::CreatePipeline:
            return "CreatePipeline";
          case TriggerType::StartPipelineExecution:
            return "StartPipelineExecution";
          case TriggerType::PollForSourceChanges:
            return "PollForSourceChanges";
          case TriggerType::Webhook:
            return "Webhook";
          case TriggerType::CloudWatchEvent:
            return "CloudWatchEvent";
          case TriggerType::PutActionRevision:
            return "PutActionRevision";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace TriggerTypeMapper
    } // namespace Model
  } // namespace CodePipeline
} // namespace Aws