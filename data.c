#include <stdio.h>
#include <stdlib.h>

int main()
{
//imagine we have a currency that starts at a rate r compared to american dollars
//and then increases over a weeklong period by a very small amount

int i,j,k,l;

//initialize our days and weeks

int totaldays = 14;
int weeklength = 7;

//for counting the streaks, we need an array and a counter set to 0

int streak = 0;
int max = 0;
float db[totaldays];

float r = 2.05;

for (i = 0; i<weeklength;i++)
{
	r *= 1.006;
	printf("%f\n",r);
	db[i] = r;
}
//Now lets show a decrease on this currency exchange over the next week
for (j = 0; j<weeklength;j++)
{
	r *= .95;
	printf("%f\n",r);
	db[j+7] = r;
}

// Lets write an algorithm to find and increase in value over 
//and record the streak (should be 7)
k = 0;

while (k+1 < totaldays)
{
//indexing error
	if (db[k+1] >= db[k])
		streak+=1;
	else if (db[k+1] < db[k])
		streak = 0;
	if (streak > max)
		max = streak;

    k++;
}
printf("%d\n", max);
//free(db);

}
