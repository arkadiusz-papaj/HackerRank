class D : public A,B,C
{
	int val{1};
	public:
		//Implement this function
		auto update_val(int new_val) -> void {
            while (new_val % 2 == 0) {
                new_val /= 2;
                A::func(val);
            }
            
            while (new_val % 3 == 0) {
                new_val /= 3;
                B::func(val);
            }
            
            while (new_val % 5 == 0) {
                new_val /= 5;
                C::func(val);
            }
		 }
		 //For Checking Purpose
		 auto check(int) -> void; //Do not delete this line.
};