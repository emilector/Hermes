// Copyright (c) ASM Assembly Systems GmbH & Co. KG
#pragma once
#include <HermesData.hpp>

namespace Hermes
{

    class UpstreamConnection
    {
    public:
        UpstreamConnection(IAsioServiceSp, const UpstreamSettings&, const UpstreamConfiguration&);

        SignalResult Connect(const ServiceDescription&);
        SignalResult Signal(const MachineReadyData&);
        SignalResult Signal(const RevokeMachineReadyData&);
        SignalResult Signal(const StartTransportData&);
        SignalResult Signal(const StopTransportData&);
        SignalResult SendNotification(const NotificationData&);
        SignalResult Disconnect(EHermesNotificationCode, EHermesSeverity);

    };

    struct IUpstreamConnectionCallback
    {
        virtual void OnConnected(UpstreamConnection&, EHermesState, const ServiceDescription&) = 0;
        virtual void OnBoardAvailable(UpstreamConnection&, EHermesState, const BoardAvailableData&) = 0;
        virtual void OnRevokeBoardAvailable(UpstreamConnection&, EHermesState, const RevokeBoardAvailableData&) = 0;
        virtual void OnTransportFinished(UpstreamConnection&, EHermesState, const TransportFinishedData&) = 0;
        virtual void OnDisconnected(UpstreamConnection&, EHermesState) = 0;

        virtual void (UpstreamConnection&, EHermesState, const NotificationData&) = 0;
    };


}
