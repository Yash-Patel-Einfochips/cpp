
#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include <vector>

class TaskScheduler {
public:

    void scheduleTask(const std::function<void()>& task, int delayInSeconds) {
        std::thread([task, delayInSeconds]() {
            std::this_thread::sleep_for(std::chrono::seconds(delayInSeconds));
            task();
        }).detach();

    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.scheduleTask([]() {
        std::cout << "Task 1 executed after 1 second" << std::endl;
    }, 1);

    scheduler.scheduleTask([]() {
        std::cout << "Task 2 executed after 3 seconds" << std::endl;
    }, 3);

    scheduler.scheduleTask([]() {
        std::cout << "Task 3 executed after 2 seconds" << std::endl;
    }, 2);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
