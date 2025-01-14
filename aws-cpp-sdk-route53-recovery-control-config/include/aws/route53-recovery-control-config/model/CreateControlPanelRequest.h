﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/route53-recovery-control-config/Route53RecoveryControlConfig_EXPORTS.h>
#include <aws/route53-recovery-control-config/Route53RecoveryControlConfigRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>
#include <aws/core/utils/UUID.h>

namespace Aws
{
namespace Route53RecoveryControlConfig
{
namespace Model
{

  /**
   * <p>The details of the control panel that you're creating.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/route53-recovery-control-config-2020-11-02/CreateControlPanelRequest">AWS
   * API Reference</a></p>
   */
  class AWS_ROUTE53RECOVERYCONTROLCONFIG_API CreateControlPanelRequest : public Route53RecoveryControlConfigRequest
  {
  public:
    CreateControlPanelRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateControlPanel"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>Unique client idempotency token.</p>
     */
    inline const Aws::String& GetClientToken() const{ return m_clientToken; }

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline bool ClientTokenHasBeenSet() const { return m_clientTokenHasBeenSet; }

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline void SetClientToken(const Aws::String& value) { m_clientTokenHasBeenSet = true; m_clientToken = value; }

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline void SetClientToken(Aws::String&& value) { m_clientTokenHasBeenSet = true; m_clientToken = std::move(value); }

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline void SetClientToken(const char* value) { m_clientTokenHasBeenSet = true; m_clientToken.assign(value); }

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline CreateControlPanelRequest& WithClientToken(const Aws::String& value) { SetClientToken(value); return *this;}

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline CreateControlPanelRequest& WithClientToken(Aws::String&& value) { SetClientToken(std::move(value)); return *this;}

    /**
     * <p>Unique client idempotency token.</p>
     */
    inline CreateControlPanelRequest& WithClientToken(const char* value) { SetClientToken(value); return *this;}


    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline const Aws::String& GetClusterArn() const{ return m_clusterArn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline bool ClusterArnHasBeenSet() const { return m_clusterArnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline void SetClusterArn(const Aws::String& value) { m_clusterArnHasBeenSet = true; m_clusterArn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline void SetClusterArn(Aws::String&& value) { m_clusterArnHasBeenSet = true; m_clusterArn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline void SetClusterArn(const char* value) { m_clusterArnHasBeenSet = true; m_clusterArn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline CreateControlPanelRequest& WithClusterArn(const Aws::String& value) { SetClusterArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline CreateControlPanelRequest& WithClusterArn(Aws::String&& value) { SetClusterArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the cluster for the control panel.</p>
     */
    inline CreateControlPanelRequest& WithClusterArn(const char* value) { SetClusterArn(value); return *this;}


    /**
     * <p>The name of the control panel.</p>
     */
    inline const Aws::String& GetControlPanelName() const{ return m_controlPanelName; }

    /**
     * <p>The name of the control panel.</p>
     */
    inline bool ControlPanelNameHasBeenSet() const { return m_controlPanelNameHasBeenSet; }

    /**
     * <p>The name of the control panel.</p>
     */
    inline void SetControlPanelName(const Aws::String& value) { m_controlPanelNameHasBeenSet = true; m_controlPanelName = value; }

    /**
     * <p>The name of the control panel.</p>
     */
    inline void SetControlPanelName(Aws::String&& value) { m_controlPanelNameHasBeenSet = true; m_controlPanelName = std::move(value); }

    /**
     * <p>The name of the control panel.</p>
     */
    inline void SetControlPanelName(const char* value) { m_controlPanelNameHasBeenSet = true; m_controlPanelName.assign(value); }

    /**
     * <p>The name of the control panel.</p>
     */
    inline CreateControlPanelRequest& WithControlPanelName(const Aws::String& value) { SetControlPanelName(value); return *this;}

    /**
     * <p>The name of the control panel.</p>
     */
    inline CreateControlPanelRequest& WithControlPanelName(Aws::String&& value) { SetControlPanelName(std::move(value)); return *this;}

    /**
     * <p>The name of the control panel.</p>
     */
    inline CreateControlPanelRequest& WithControlPanelName(const char* value) { SetControlPanelName(value); return *this;}

  private:

    Aws::String m_clientToken;
    bool m_clientTokenHasBeenSet;

    Aws::String m_clusterArn;
    bool m_clusterArnHasBeenSet;

    Aws::String m_controlPanelName;
    bool m_controlPanelNameHasBeenSet;
  };

} // namespace Model
} // namespace Route53RecoveryControlConfig
} // namespace Aws
