/* Copyright (C) 2005-2011, Thorvald Natvig <thorvald@natvig.com>
   Copyright (C) 2009-2011, Stefan Hacker <dd0t@users.sourceforge.net>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "mumble_pch.hpp"

#include "MessageHandler.h"
#include "ServerHandler.h"
#include "Global.h"

MessageHandler::MessageHandler(QObject *parent) : QObject(parent) {}

void MessageHandler::customEvent(QEvent *evt) {
	if (evt->type() != SERVERSEND_EVENT) {
			return;
	}

	ServerHandlerMessageEvent *shme=static_cast<ServerHandlerMessageEvent *>(evt);

#ifdef QT_NO_DEBUG
#define MUMBLE_MH_MSG(x) case MessageHandler:: x : { \
		MumbleProto:: x msg; \
		if (msg.ParseFromArray(shme->qbaMsg.constData(), shme->qbaMsg.size())) \
			msg##x(msg); \
		break; \
	}
#else
#define MUMBLE_MH_MSG(x) case MessageTypes:: x : { \
		MumbleProto:: x msg; \
		if (msg.ParseFromArray(shme->qbaMsg.constData(), shme->qbaMsg.size())) { \
			printf("%s:\n", #x); \
			msg.PrintDebugString(); \
			msg##x(msg); \
		} \
		break; \
	}
#endif
	switch (shme->uiType) {
			MUMBLE_MH_ALL
	}


#undef MUMBLE_MH_MSG
}

void MessageHandler::msgAuthenticate(const MumbleProto::Authenticate &) {
	// Not handled on client
}

void MessageHandler::msgBanList(const MumbleProto::BanList &msg) {
	g.mw->msgBanList(msg);
}

void MessageHandler::msgReject(const MumbleProto::Reject &msg) {
	g.mw->msgReject(msg);
}

void MessageHandler::msgServerSync(const MumbleProto::ServerSync &msg) {
	g.mw->msgServerSync(msg);
}


void MessageHandler::msgServerConfig(const MumbleProto::ServerConfig &msg) {
	g.mw->msgServerConfig(msg);
}

void MessageHandler::msgPermissionDenied(const MumbleProto::PermissionDenied &msg) {
	g.mw->msgPermissionDenied(msg);
}

void MessageHandler::msgUDPTunnel(const MumbleProto::UDPTunnel &) {
	// Not handled on client
}

void MessageHandler::msgUserState(const MumbleProto::UserState &msg) {
	g.mw->msgUserState(msg);
}

void MessageHandler::msgUserRemove(const MumbleProto::UserRemove &msg) {
	g.mw->msgUserRemove(msg);
}

void MessageHandler::msgChannelState(const MumbleProto::ChannelState &msg) {
	g.mw->msgChannelState(msg);
}

void MessageHandler::msgChannelRemove(const MumbleProto::ChannelRemove &msg) {
	g.mw->msgChannelRemove(msg);
}

void MessageHandler::msgTextMessage(const MumbleProto::TextMessage &msg) {
	g.mw->msgTextMessage(msg);
}

void MessageHandler::msgACL(const MumbleProto::ACL &msg) {
	g.mw->msgACL(msg);
}

void MessageHandler::msgQueryUsers(const MumbleProto::QueryUsers &msg) {
	g.mw->msgQueryUsers(msg);
}

void MessageHandler::msgPing(const MumbleProto::Ping &) {
	// Not handled on client
}

void MessageHandler::msgCryptSetup(const MumbleProto::CryptSetup &msg) {
	g.mw->msgCryptSetup(msg);
}

void MessageHandler::msgContextAction(const MumbleProto::ContextAction &) {
	// Not handled on client
}

void MessageHandler::msgContextActionModify(const MumbleProto::ContextActionModify &msg) {
	g.mw->msgContextActionModify(msg);
}

void MessageHandler::msgVersion(const MumbleProto::Version &msg) {
	g.mw->msgVersion(msg);
}

void MessageHandler::msgUserList(const MumbleProto::UserList &msg) {
	g.mw->msgUserList(msg);
}

void MessageHandler::msgVoiceTarget(const MumbleProto::VoiceTarget &) {
	// Not handled on client
}

void MessageHandler::msgPermissionQuery(const MumbleProto::PermissionQuery &msg) {
	g.mw->msgPermissionQuery(msg);
}

void MessageHandler::msgCodecVersion(const MumbleProto::CodecVersion &msg) {
	g.mw->msgCodecVersion(msg);
}

void MessageHandler::msgUserStats(const MumbleProto::UserStats &msg) {
	g.mw->msgUserStats(msg);
}

void MessageHandler::msgRequestBlob(const MumbleProto::RequestBlob &) {
	// Not handled on client
}

void MessageHandler::msgSuggestConfig(const MumbleProto::SuggestConfig &msg) {
	g.mw->msgSuggestConfig(msg);
}
