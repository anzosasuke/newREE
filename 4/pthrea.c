#include <pthread.h>
#include<stdio.h>

pthread_mutex_t count_mutex;
pthread_mutex_t count_mutex_1;
long count;
long count1;

void
increment_count()
{
	    pthread_mutex_lock(&count_mutex);
    count = count + 1;
	    pthread_mutex_lock(&count_mutex_1);
	    count1 = count1 + 2;

	    pthread_mutex_unlock(&count_mutex);
	    pthread_mutex_unlock(&count_mutex_1);
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

int main()
{
increment_count();
get_count();

return 0;

}