#ifndef TESTIAPPAPP_H
#define TESTIAPPAPP_H

#include "MooseApp.h"

class TestiappApp;

template<>
InputParameters validParams<TestiappApp>();

class TestiappApp : public MooseApp
{
public:
  TestiappApp(InputParameters parameters);
  virtual ~TestiappApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TESTIAPPAPP_H */
