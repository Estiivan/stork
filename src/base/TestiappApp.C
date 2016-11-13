#include "TestiappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<TestiappApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

TestiappApp::TestiappApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TestiappApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TestiappApp::associateSyntax(_syntax, _action_factory);
}

TestiappApp::~TestiappApp()
{
}

// External entry point for dynamic application loading
extern "C" void TestiappApp__registerApps() { TestiappApp::registerApps(); }
void
TestiappApp::registerApps()
{
  registerApp(TestiappApp);
}

// External entry point for dynamic object registration
extern "C" void TestiappApp__registerObjects(Factory & factory) { TestiappApp::registerObjects(factory); }
void
TestiappApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void TestiappApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { TestiappApp::associateSyntax(syntax, action_factory); }
void
TestiappApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
