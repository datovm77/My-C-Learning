#include <iostream>

constexpr int MAX_SIZE = 10;

struct SharedStack {
    int data[MAX_SIZE];
    int top1;
    int top2;
};

void InitSharedStack(SharedStack &stack) {
    stack.top1 = -1;
    stack.top2 = MAX_SIZE;
}

bool IsFull(const SharedStack &stack) {
    return stack.top1 + 1 == stack.top2;
}

bool IsEmpty(const SharedStack &stack, int stackNumber) {
    if (stackNumber == 1) {
        return stack.top1 == -1;
    }

    if (stackNumber == 2) {
        return stack.top2 == MAX_SIZE;
    }

    return true;
}

int GetFreeSpace(const SharedStack &stack) {
    return stack.top2 - stack.top1 - 1;
}

bool Push(SharedStack &stack, int stackNumber, int value) {
    if (stackNumber != 1 && stackNumber != 2) {
        return false;
    }

    if (IsFull(stack)) {
        return false;
    }

    if (stackNumber == 1) {
        stack.data[++stack.top1] = value;
    } else {
        stack.data[--stack.top2] = value;
    }

    return true;
}

bool Pop(SharedStack &stack, int stackNumber, int &value) {
    if (stackNumber != 1 && stackNumber != 2) {
        return false;
    }

    if (IsEmpty(stack, stackNumber)) {
        return false;
    }

    if (stackNumber == 1) {
        value = stack.data[stack.top1--];
    } else {
        value = stack.data[stack.top2++];
    }

    return true;
}

bool GetTop(
    const SharedStack &stack,
    int stackNumber,
    int &value
) {
    if (stackNumber != 1 && stackNumber != 2) {
        return false;
    }

    if (IsEmpty(stack, stackNumber)) {
        return false;
    }

    if (stackNumber == 1) {
        value = stack.data[stack.top1];
    } else {
        value = stack.data[stack.top2];
    }

    return true;
}

int main() {
    SharedStack stack;
    InitSharedStack(stack);

    Push(stack, 1, 10);
    Push(stack, 1, 20);

    Push(stack, 2, 100);
    Push(stack, 2, 90);

    std::cout << "Free positions: "
              << GetFreeSpace(stack) << '\n';

    int value;

    if (GetTop(stack, 1, value)) {
        std::cout << "Stack 1 top: " << value << '\n';
    }

    if (GetTop(stack, 2, value)) {
        std::cout << "Stack 2 top: " << value << '\n';
    }

    if (Pop(stack, 1, value)) {
        std::cout << "Stack 1 popped: " << value << '\n';
    }

    if (Pop(stack, 2, value)) {
        std::cout << "Stack 2 popped: " << value << '\n';
    }

    std::cout << "Free positions after popping: "
              << GetFreeSpace(stack) << '\n';

    return 0;
}
