namespace A {
    namespace B {
        int x{10};
    }

    inline namespace C
    {
        int z{20};
    } // namespace C
    
}

int main(int argc, char const *argv[])
{
    int a = A::B::x;
    int b = A::z;
    return 0;
}
