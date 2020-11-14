#ifndef CLTHREAD_H
#define CLTHREAD_H

#include<pthread.h>
#include<iostream>
#include "CLExecutiveFunctions.h"

class CLThread
{
    public:
        explicit CLThread(CLExecutiveFunctions* pExecutiveFunctionProvider){
            m_pExecutiveFunctionProvider = pExecutiveFunctionProvider;
        };
        virtual ~CLThread(){};
        virtual void Run();
        virtual void WaitForDeath();

    private:
        static void* StartFunctionOfThread(void* pThis);

    private:
        CLExecutiveFunctions* m_pExecutiveFunctionProvider;
        pthread_t m_ThreadID;
};


#endif // CLTHREAD_H
