#include <pthread.h>
#include<stdio.h>

pthread_mutex_t count_mutex;
pthread_mutex_t count_mutex_1;
pthread_mutex_t mtx1;
pthread_mutex_t mtx2;

long count;
long count1;

void
increment_count()
{
			pthread_mutex_init(&count_mutex, NULL);
			pthread_mutex_init(&count_mutex_1, NULL);
	    pthread_mutex_lock(&count_mutex);
    count = count + 1;
	    pthread_mutex_lock(&count_mutex_1);
	    count1 = count1 + 2;
	    pthread_mutex_unlock(&count_mutex);
	    pthread_mutex_unlock(&count_mutex_1);
			pthread_mutex_destroy(&count_mutex);
}
void bad1(void)
{
  pthread_mutex_init(&mtx1, NULL);
  pthread_mutex_init(&mtx1, NULL);

}

void bad2(void)
{
  pthread_mutex_init(&mtx1, NULL);
  pthread_mutex_lock(&mtx1);
  pthread_mutex_destroy(&mtx1);
}


void bad3(void)
{
  pthread_mutex_init(&mtx1, NULL);
  pthread_mutex_destroy(&mtx1);
  pthread_mutex_destroy(&mtx1);
}

void bad4(void)
{
  pthread_mutex_init(&mtx1, NULL);
  pthread_mutex_destroy(&mtx1);
  pthread_mutex_lock(&mtx1);
}

void bad5(void)
{
  pthread_mutex_init(&mtx1, NULL);
  pthread_mutex_destroy(&mtx1);
  pthread_mutex_unlock(&mtx1);
}
void bad6(void)
{
	pthread_mutex_init(&mtx1, NULL);
	int i = 0;
	while(i<4)
	{
		if(i == 1)
		{
			pthread_mutex_lock(&mtx2);
			pthread_mutex_lock(&mtx1);
		}
		else if(i == 2)
		{
			pthread_mutex_unlock(&mtx1);
		}
		else if(i == 3)
		{
			pthread_mutex_destroy(&mtx1);
		}
		i = i + 1;
}
}
void another(void){
	pthread_mutex_init(&mtx1, NULL);
	int p = 1;
	for(int i=0; i<5; i++){
		;
	}

		pthread_mutex_lock(&mtx1);

		for(int i=0; i<5; i++){
			;
		}



pthread_mutex_unlock(&mtx1);
for(int i=0; i<5; i++){
	;
}
pthread_mutex_destroy(&mtx2);
if (p==1){
pthread_mutex_destroy(&mtx1);
}
}


long
get_count()
{
    long c;
    long c1;

  pthread_mutex_lock(&count_mutex);
	    c = count;
	pthread_mutex_lock(&count_mutex_1);
		c1 = count1;
  pthread_mutex_unlock(&count_mutex_1);
  pthread_mutex_unlock(&count_mutex);
	printf("%ld", c1);
	    return (c);

}
void mult2(void)
{
	pthread_mutex_lock(&mtx1);
	pthread_mutex_unlock(&mtx1);
	pthread_mutex_destroy(&mtx1);

}
void mult1(void)
{
	pthread_mutex_init(&mtx1, NULL);
	mult2();
}



int main()
{
increment_count();
get_count();
bad1();
bad2();
bad3();
bad4();
bad5();
bad6();
another();
mult1();

return 0;

}
