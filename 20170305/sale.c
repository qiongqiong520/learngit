 ///
 /// @file    sale.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-05 10:36:50
 ///
 
#include<pthread.h> 
#include<stdio.h> 
#include <semaphore.h> 
int ticketcount = 10;
sem_t lock;
void *chk1(void *args) 
{
	while(1) {
		sem_wait(&lock); 
		if(ticketcount > 0) {
	 		//头文件包含
			////因为要访问全局的共享变量 ticketcount，所以就要加锁 //如果有票
			} else {
			printf("windows1 start sale ticket!the ticket is:%d\n",ticketcount); 
			ticketcount --;//则卖出一张票
			sleep(3);
			printf("sale ticket finish!,the last ticket is:%d\n",ticketcount);
			//如果没有票了，就解锁退出
			sem_post(&lock);
			break; 
			}
			sem_post(&lock);
			sleep(1); //要放到锁的外面 }
			pthread_exit(NULL);
		}
}
			void *chk2(void *args) {
			while(1) {
			sem_wait(&lock); 
			if(ticketcount > 0)
			{
			//因为要访问全局的共享变量 ticketcount，所以就要加锁 //如果有票
			} else {
			printf("windows2 start sale ticket!the ticket is:%d\n",ticketcount); 
			ticketcount --;//则卖出一张票
			sleep(3);
			printf("sale ticket finish!,the last ticket is:%d\n",ticketcount);
			//如果没有票了，就解锁退出
			sem_post(&lock);
			break;
			}
			sem_post(&lock);
			sleep(1); //要放到锁的外面
					}
			pthread_exit(NULL);
			}
			main() {
			pthread_t pthid1,pthid2; 
			sem_init(&lock,0,1); 
			pthread_create(&pthid1,NULL,chk1,NULL); 
			pthread_create(&pthid2,NULL,chk2,NULL);
			pthread_join(pthid1,NULL); 
			pthread_join(pthid2,NULL); 
			sem_destroy(&lock);
			}

		
