#pragma once

void run(int deltaX1, int deltaY1, int deltaX2, int deltaY2) // может можно было и проще
{
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 0; }
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 0; }
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 1; }
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 1; }
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == -1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = -1; deltaX1 = 0; }

	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 0; }
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 0; }
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 1; }
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 1; }
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 0) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaX1 = 1; deltaY1 = -1; deltaX2 = -1; deltaY2 = -1; }
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;

	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 0; }
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 0; }
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 1; }
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 1; }
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaX1 == 1) && (deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = 2; deltaX2 = 2; deltaY1 = 2; deltaX1 = 2; }
}

void run(int deltaY1, int deltaX2, int deltaY2)
{
	if ((deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == -1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == -1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == -1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 0; }
	if ((deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 0) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 0; }
	if ((deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 0) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = 1; }
	if ((deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 0) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = -1; deltaX2 = -1; deltaY1 = 1; }
	if ((deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 1) && (deltaX2 == -1) && (deltaY2 == 1)) { deltaY2 = -1;  deltaX2 = 0; }
	if ((deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 1) && (deltaX2 == 0) && (deltaY2 == 1)) { deltaX2 = 1; deltaY2 = -1; }
	if ((deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == -1)) deltaY2 = 0;
	if ((deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 0)) deltaY2 = 1;
	if ((deltaY1 == 1) && (deltaX2 == 1) && (deltaY2 == 1)) { deltaY2 = 2; deltaX2 = 2; deltaY1 = 2; }
	
}