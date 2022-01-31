namespace X8_3 {
	using uns_char             = unsigned char;
	using const_uns_char       = const unsigned char;
	using int_ptr              = int *;
	using char_ptr_ptr         = char **;
	// pointer to array of `char`: can use arbirary array size, or use
	//   char ** for pointer to array of unspecified size
	using char_arr_ptr         = char (*)[5];
	// array of 7 pointers to `int`:
	using _7_int_ptr_arr       = int *[7];
	// pointer to an array of 7 pointers to `int`:
	//   - https://stackoverflow.com/questions/6130712
	using _7_int_ptr_arr_ptr   = int *(*)[7];
	// array of 8 arrays of 7 pointers to `int`:
	using _8_arr_7_int_ptr_arr = int *[8][7];
}  // namespace X8_3


int main() {
	char arr[5] = "test";
	char c {'~'};
	int i0 {0}, i1 {1}, i2 {2}, i3 {3}, i4 {4}, i5 {5}, i6 {6};

	X8_3::uns_char             uc {'a'};
	X8_3::const_uns_char       cuc {'b'};
	X8_3::int_ptr              ip {nullptr};
	X8_3::char_ptr_ptr         cpp {nullptr};
	X8_3::char_arr_ptr         cap {&arr};
	X8_3::_7_int_ptr_arr       _7ipa { &i0, &i1, &i2, &i3, &i4, &i5, &i6 };
	X8_3::_7_int_ptr_arr_ptr   _7ipap { &_7ipa };
	X8_3::_8_arr_7_int_ptr_arr _8a7ipa = {
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 },
		{ &i0, &i1, &i2, &i3, &i4, &i5, &i6 }
	};
}
