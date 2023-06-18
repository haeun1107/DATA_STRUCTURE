for (int i = 1; i <= 10; i++) { 
		n = i * 1000;
		printf("\n ----- n = %d ----- \n", n); 
		random_initialize(experiment, n);

		copy_list(experiment, exp_list, n);
		num_compare = 0; insertion_sort(exp_list, n, 0);
		printf("\n No. of comparison (insertion sort) = %d \n", num_compare);

		copy_list(experiment, exp_list, n);
		num_compare = 0; quick_sort(exp_list, 0, n - 1, 0);
		printf("\n No. of comparison (quick sort) = %d \n", num_compare);

		copy_list(experiment, exp_list, n);
		num_compare = 0; merge_sort(exp_list, 0, n - 1, 0);
		printf("\n No. of comparison (merge sort) = %d \n", num_compare);
	}