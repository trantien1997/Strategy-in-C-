#include <iostream>

class FlyBehavior {
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        std::cout << "Bay cao lên nào" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        std::cout << "Không thể bay được" << std::endl;
    }
};

class QuackBehavior {
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Quack quack..." << std::endl;
    }
};

class Squek : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Squek squek..." << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Không thể kêu" << std::endl;
    }
};

class Duck {
protected:
    // FlyBehavior là một lớp trừu tượng, không thể tạo trực tiếp một đồi tượng FlyBehavior. Thay vì khai báo trường FlyBehavior flyBehavior, nên sử
    // dụng con trỏ hoặc tham chiếu đến FlyBehavior
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(FlyBehavior* fly, QuackBehavior* quack)
        : flyBehavior(fly), quackBehavior(quack) {}

    void performQuack() {
        quackBehavior->quack();
    }

    void performFly() {
        flyBehavior->fly();
    }

    virtual void display() = 0;
};

class MallarDuck : public Duck {
public:
    MallarDuck()
        : Duck(new FlyNoWay(), new MuteQuack()) {} // Khởi tạo con trỏ

    void display() override {
        std::cout << "I'm a real MallarDuck duck" << std::endl;
    }
};

int main() {
    Duck* mallarDuck = new MallarDuck();
    mallarDuck->performFly();
    mallarDuck->performQuack();
    mallarDuck->display();

    // Giải phóng bộ nhớ (xóa con trỏ)
    delete mallarDuck;

    return 0;
}
