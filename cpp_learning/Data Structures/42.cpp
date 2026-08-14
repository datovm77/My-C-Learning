constexpr int MAX_SIZE = 100;

struct ArrayStack
{
    int data[MAX_SIZE];
    int top;
};

bool IsEmpty(const ArrayStack &stack)
{
    return stack.top == -1;
}

bool IsFull(const ArrayStack &stack)
{
    return stack.top == MAX_SIZE - 1;
}

// 请完整写出
bool Push(ArrayStack &stack, int value)
{
    if (!IsFull(stack))
    {
        stack.data[++stack.top] = value;
        return true;
    }

    return false;
}

// 请完整写出
bool Pop(ArrayStack &stack, int &value)
{
    if (!IsEmpty(stack))
    {
        value = stack.data[stack.top--];
        return true;
    }
    return false;
}