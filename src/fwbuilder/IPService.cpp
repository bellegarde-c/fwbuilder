/* 

                          Firewall Builder

                 Copyright (C) 2000 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

  $Id$


  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include <assert.h>

#include <fwbuilder/libfwbuilder-config.h>

#include <fwbuilder/IPService.h>
#include <fwbuilder/XMLTools.h>

using namespace libfwbuilder;
using namespace std;

const char *IPService::TYPENAME={"IPService"};

IPService::IPService() 
{
    setStr("protocol_num", "");
}

IPService::IPService(const FWObject *root,bool prepopulate) : Service(root,prepopulate)
{
    setStr("protocol_num", "");
}

IPService::~IPService() {}

string IPService::getProtocolName()
{
    if      (getInt("protocol_num")==0)  return "ip";
    else if (getInt("protocol_num")==1)  return "icmp";
    else if (getInt("protocol_num")==6)  return "tcp";
    else if (getInt("protocol_num")==17) return "udp";
    else return getStr("protocol_num");
}

int    IPService::getProtocolNumber()
{
    return getInt("protocol_num");
}


void IPService::fromXML(xmlNodePtr root) throw(FWException)
{
    FWObject::fromXML(root);

    const char *n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("protocol_num")));
    assert(n!=NULL);
    setStr("protocol_num", n);
    FREEXMLBUFF(n);

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("fragm")));
    if(n!=NULL)
    {
        setStr("fragm", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("short_fragm")));
    if(n!=NULL)
    {
        setStr("short_fragm", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("lsrr")));
    if(n!=NULL)
    {
        setStr("lsrr", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("ssrr")));
    if(n!=NULL)
    {
        setStr("ssrr", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("rr")));
    if(n!=NULL)
    {
        setStr("rr", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("ts")));
    if(n!=NULL)
    {
        setStr("ts", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("tos")));
    if(n!=NULL)
    {
        setStr("tos", n);
        FREEXMLBUFF(n);
    }

    n=FROMXMLCAST(xmlGetProp(root,TOXMLCAST("dscp")));
    if(n!=NULL)
    {
        setStr("dscp", n);
        FREEXMLBUFF(n);
    }
}

string IPService::getTOSCode()
{
    return getStr("tos");
}

void IPService::setTOSCode(const string &c)
{
    setStr("tos", c);
}

string IPService::getDSCPCode()
{
    return getStr("dscp");
}

void IPService::setDSCPCode(const string &c)
{
    setStr("dscp", c);
}








