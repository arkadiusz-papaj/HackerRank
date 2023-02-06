//run this as C++ or C++14. C++20 is so optimised that exceptions are not thrown        
        try {
            cout << Server::compute(A, B) << endl;
        }
        catch (const std::bad_alloc& e) {
            cout << "Not enough memory" << endl;
        }
        catch (const std::exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (...) {
            cout << "Other Exception" << endl;
        }