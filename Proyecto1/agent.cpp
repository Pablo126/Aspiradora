#include "agent.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;
// -----------------------------------------------------------
/*
1.Analizar que ha pasado
2.Construir mundo

Average dirty degree sobre un mapa que no es ninguno de los dados con 10 ejecuciones
23 Abril a las 23:59-->decsai entrega de practicas
2000iteraciones 100 casillas
*/
// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion;

   if(dirty_)
      accion = actSUCK;
   else
   {
      if(bump_ or n_avances_>3)
      {
         switch(rand()%2+1)
         {
            case 1: accion = actTURN_L;
               break;
            case 2: accion = actTURN_R;
               break;
         }
         n_avances_=0;
      }
      else
      {
         switch(rand()%3)
         {
            case 0:
               accion = actFORWARD;
               n_avances_++;
               break;
            case 1:
               accion = actTURN_L;
               n_avances_=0;
               break;
            case 2:
               accion = actTURN_R;
               n_avances_=0;
               break;
         }
      }
   }
	return accion;
}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	bump_ = env.isJustBump();
	dirty_ = env.isCurrentPosDirty();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actSUCK: return "SUCK";
	case Agent::actIDLE: return "IDLE";
	default: return "???";
	}
}
