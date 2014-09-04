/*
 * Copyright (c) 2014, webvariants GmbH, http://www.webvariants.de
 *
 * This file is released under the terms of the MIT license. You can find the
 * complete text in the attached LICENSE file or online at:
 *
 * http://www.opensource.org/licenses/mit-license.php
 *
 * @author: Christian Sonderfeld (christian.sonderfeld@webvariants.de)
 */


#ifndef __AUTH_CONTROLLERCOMPONENT__
#define __AUTH_CONTROLLERCOMPONENT__

#include "AuthController.h"
#include "world/BaseComponent.h"

namespace Susi {
namespace Auth {

class ControllerComponent : Controller, Susi::System::BaseComponent
{
protected:
	void handleLogin(Susi::Events::EventPtr event);
	void handleLogout(Susi::Events::EventPtr event);
	void handleIsLoggedIn(Susi::Events::EventPtr event);
	void handleGetUsername(Susi::Events::EventPtr event);

public:
	ControllerComponent(Susi::System::ComponentManager * mgr, std::string db_identifier) :
		Controller{db_identifier},
		Susi::System::BaseComponent{mgr}
		{}

	virtual void start() override {
		subscribe("auth::login", handleLogin);
		subscribe("auth::logout", handleLogout);
		subscribe("auth::isLoggedIn", handleIsLoggedIn);
		subscribe("auth::getUsername", handleGetUsername);
	}

	virtual void stop() override {
		unsubscribeAll();
	}

	~ControllerComponent() {stop();}
};

}
}

#endif // __AUTH_CONTROLLERCOMPONENT__
