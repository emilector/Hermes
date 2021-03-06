// Copyright (c) ASM Assembly Systems GmbH & Co. KG
#pragma once

#include <HermesData.hpp>

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/mpl/vector.hpp>

using HermesDataTypes = boost::mpl::vector<
    //Hermes::CheckAliveData,
    Hermes::UpstreamConfiguration,
    Hermes::DownstreamConfiguration,
    //Hermes::GetConfigurationData,
    Hermes::SetConfigurationData,
    Hermes::CurrentConfigurationData,
    Hermes::ConnectionInfo,
    Hermes::ServiceDescription,
    Hermes::MachineReadyData,
    //Hermes::RevokeMachineReadyData,
    Hermes::BoardAvailableData,
    //Hermes::RevokeBoardAvailableData,
    Hermes::StartTransportData,
    Hermes::StopTransportData,
    Hermes::TransportFinishedData,
    Hermes::NotificationData,
    Hermes::UpstreamSettings,
    Hermes::DownstreamSettings,
    Hermes::ConfigurationServiceSettings
>;

BOOST_FUSION_ADAPT_STRUCT(Hermes::UpstreamConfiguration,
    m_upstreamLaneId,
    m_hostAddress,
    m_port
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::DownstreamConfiguration,
    m_downstreamLaneId,
    m_optionalClientAddress,
    m_port
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::SetConfigurationData,
    m_machineId,
    m_upstreamConfigurations,
    m_downstreamConfigurations
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::CurrentConfigurationData,
    m_optionalMachineId,
    m_upstreamConfigurations,
    m_downstreamConfigurations
)
//BOOST_FUSION_ADAPT_STRUCT(Hermes::GetConfigurationData)
BOOST_FUSION_ADAPT_STRUCT(Hermes::ConnectionInfo,
    m_address,
    m_port
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::ServiceDescription,
    m_laneId,
    m_machineId,
    m_version
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::MachineReadyData,
    m_failedBoard
)
//BOOST_FUSION_ADAPT_STRUCT(Hermes::RevokeMachineReadyData)
BOOST_FUSION_ADAPT_STRUCT(Hermes::BoardAvailableData,
    m_boardId,
    m_boardIdCreatedBy,
    m_failedBoard,
    m_optionalProductTypeId,
    m_flippedBoard,
    m_optionalTopBarcode,
    m_optionalBottomBarcode,
    m_optionalLengthInMM,
    m_optionalWidthInMM,
    m_optionalThicknessInMM,
    m_optionalConveyorSpeedInMMPerSecs,
    m_optionalTopClearanceHeightInMM,
    m_optionalBottomClearanceHeightInMM
)
//BOOST_FUSION_ADAPT_STRUCT(Hermes::RevokeBoardAvailableData)
BOOST_FUSION_ADAPT_STRUCT(Hermes::StartTransportData,
    m_boardId,
    m_optionalConveyorSpeedInMMPerSecs
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::StopTransportData,
    m_transferState,
    m_boardId
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::TransportFinishedData,
    m_transferState,
    m_boardId
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::NotificationData,
    m_notificationCode,
    m_severity,
    m_description
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::UpstreamSettings,
    m_machineId,
    m_hostAddress,
    m_port,
    m_checkAlivePeriodInSeconds,
    m_reconnectWaitTimeInSeconds,
    m_checkState
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::DownstreamSettings,
    m_machineId,
    m_optionalClientAddress,
    m_port,
    m_checkAlivePeriodInSeconds,
    m_reconnectWaitTimeInSeconds,
    m_checkState
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::ConfigurationServiceSettings,
    m_port,
    m_reconnectWaitTimeInSeconds
)
BOOST_FUSION_ADAPT_STRUCT(Hermes::Error,
    m_code,
    m_text
)
