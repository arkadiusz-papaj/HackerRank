auto process_input(int n) -> void {
    try {
        auto d = int{largest_proper_divisor(n)};
        std::cout << "result=" << d << '\n';
    }
    catch (invalid_argument& e) {
        std::cout << e.what() << '\n';
    }

    std::cout << "returning control flow to caller\n";
}