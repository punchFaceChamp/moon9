/*
   Copyright (c) 2002 Tokamak Limited

   Date: 2002/10/27 12:00:00 

   This software, the Tokamak Game Physics SDK and the documentaion
   has been developed by Tokamak Ltd (Tokamak) and the copyright 
   and all other intellectual property rights in this software 
   belong to Tokamak. 
   
   All rights conferred by law (including rights under international
   copyright conventions) are reserved to Tokamak. This software
   may also incorporate information which is confidential to
   Tokamak.

   Without the permission by Tokamak, this software and documentaion
   must not be copied (in whole or in part), re-arranged, altered or 
   adapted in any way. In addition, the information contained in the 
   software may not be disseminated without the prior written consent
   of Tokamak.
*/

#include "../samplebase.h"

void BreakageCallbackFn(neByte * originalBody, neBodyType bodyType, neGeometry * brokenGeometry, neRigidBody * newBody);

class CSample5: public CSampleBase
{
public:
	CSample5() { 
		paused = false;
	}
	
	void Initialise();
	
	void Shutdown();
	
	void Process(OSTime time);
	
	void DisplayText();

	void InititialisePhysics();

	void InititialiseTokens();

	void MakeTable(neV3 position, s32 index);

public:
	enum
	{
		GEOMETRY_PER_TABLE = 5,
			
		NUMBER_OF_TABLES = 15,

		NUMBER_OF_BODIES = NUMBER_OF_TABLES * GEOMETRY_PER_TABLE,
	};

	neSimulator * sim;
	
	neRigidBody * rigidBodies[NUMBER_OF_BODIES];
	
	neSimpleToken * boxToken[NUMBER_OF_BODIES];

	neAllocatorDefault all;

	nePerformanceReport perfReport;

	s32 currentBodyCount;
};
