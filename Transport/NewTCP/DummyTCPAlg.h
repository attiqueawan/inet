//
// Copyright (C) 2004 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

#ifndef __PLAINTCP_H
#define __PLAINTCP_H

#include <omnetpp.h>
#include "TCPAlgorithm.h"


/**
 * State variables for DummyTCPAlg.
 */
class DummyTCPStateVariables : public TCPStateVariables
{
  public:
    //...
};


/**
 * Includes basic TCP algorithms: retransmission, PERSIST timer, keep-alive,
 * delayed acknowledge.
 */
class DummyTCPAlg : public TCPAlgorithm
{
  protected:
    cMessage *rexmitTimer;
    cMessage *persistTimer;
    cMessage *delayedAckTimer;
    cMessage *keepAliveTimer;

    DummyTCPStateVariables *state;

  public:
    /**
     * Ctor.
     */
    DummyTCPAlg();

    /**
     * Virtual dtor.
     */
    virtual ~DummyTCPAlg();

    /**
     * Create and return a DummyTCPStateVariables object.
     */
    virtual TCPStateVariables *createStateVariables();

    virtual void established();

    virtual void processTimer(cMessage *timer, TCPEventCode& event);

    virtual void sendCommandInvoked();

    virtual void receiveSeqChanged();

    virtual void receivedDataAck();

    virtual void receivedDuplicateAck();

    virtual void receivedAckForDataNotYetSent(uint32 seq);

    virtual void ackSent();

    virtual void dataSent(uint32 fromseq);

    virtual void dataRetransmitted();
};

#endif


