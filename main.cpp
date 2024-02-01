
// Поток с Параметрами - Получение результата из потока

//#include <iostream>
//#include <thread>
//#include <chrono>
//
//
//static void Dowork(const int a,const int b){
//    for(size_t i = 0; i < 5; ++i){
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        std::cout<< "=============\t"<< "Do_work STARTED\t==============="<<std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//                 std::cout<<"a + b = "<< a + b << std::endl;
//        std::cout<<"TD Dowork "<< std::this_thread::get_id() <<"\tDowork\t" << i << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        std::cout<<"==============\t"<< "Do_work STOPPED\t================"<<std::endl;
//    }
//
//}
//
//int main()
//{
//    std::thread th(Dowork, 10 , 20);
//
//    for(size_t i = 0; i < 10; ++i){
//        std::cout<<"ID thread = "<<std::this_thread::get_id()<<"\tMain\t"<< i << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(300));
//    }
//    th.join();
//
//    return 0;
//}

 // Поток с Параметрами - Методы класса в Потоке.


//#include <iostream>
//#include <thread>
//#include<chrono>
//
//class Threads{
//public:
//    void DoWork(){
//
//        for(size_t i = 0; i <=3; ++i) {
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//            std::cout<<"============\tDoWork START\t================"<<std::endl;
//            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//            std::cout<< "ID DoWork = " <<std::this_thread::get_id()<<  "\tDoWork count "<< i <<std::endl;
//            std::cout<<"=============\tDoWork STOPPED\t==========================="<<std::endl;
//        }
//    }
//
//    void DoWork2(int a){
//
//        for(size_t i = 0; i <=3; ++i) {
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//            std::cout<<"============\tDoWork2 START\t================"<<std::endl;
//            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//            std::cout<< "ID DoWork = " <<std::this_thread::get_id()<< "\tDoWork2 count "<< i << std::endl;
//            std::cout<<"=============\tDoWork2 STOPPED\t==========================="<<std::endl;
//        }
//    }
//
//     int DoWork3(int a, int b){
//
//        for(size_t i = 0; i <=3; ++i) {
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//            std::cout<<"============\tDoWork3 START\t================"<<std::endl;
//            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//            a *=b;
//            std::cout<< "ID DoWork = " <<std::this_thread::get_id()<< "\tDoWork3 count "<< i <<std::endl;
//            std::cout<<"=============\tDoWork3 STOPPED\t==========================="<<std::endl;
//        }
//        return a + b;
//    }
//};
//
//
//
//int main(){
//
//    int f = 5;
//    int k = 10;
//   int result;
//    Threads tr;
//    std::thread t(&Threads::DoWork, tr);
//    std::thread t2(&Threads::DoWork2, tr, 5);
//   // std::thread t3(&Threads::DoWork3, tr, 5, 10);
//    std::thread t3([&]() {
//      result= tr.DoWork3(f,k);
//   });
////    std::thread t([&]()
////    {
////        result = tr.DoWork3(f, k);
////    });
//
//    std::cout<<"============\tMAIN STARTED\t===============" <<std::endl;
//    for(size_t i = 0; i <= 3; ++i){
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        std::cout<< "ID MAIN = "<< std::this_thread::get_id()<< "\tMain count\t"<< i << std::endl;
//    }
//    std::cout<<"=======================\tMAIN STOPPED\t==================="<<std::endl;
//
//      t.join();
//      t2.join();
//      t3.join();
//   std::cout << "Result = "<<result<<std::endl;
//
//    return 0;
//}


// Синхронизация Потока MUTEX + Время работы на экране Timer

#include <thread>
#include<chrono>
#include "SimpleTimer.h"
#include <mutex>

//Вывод прямоугольника из элементов которые назначим в МАЙН

std::mutex mtx;

void Print(char ch){

 std::lock_guard<std::mutex>guard(mtx);
    //mtx.lock();

    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
     // mtx.unlock();
}


int main(){
    SimpleTimer timer;

    std::thread t1(Print,'*');
    std::thread t2(Print, '#');
    std::thread t3(Print, '@');

    t1.join();
    t2.join();
    t3.join();

//    Print('*');
//    Print('#');
    return 0;
}