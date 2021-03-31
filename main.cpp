#include "utils.hpp"

#define EL_DEL_     15
#define MAX_SIZE_   15

void    synchronize(std::map<int, int> &map, std::vector<int> &vec) {
	std::pair<bool, bool> arr[10] = {};

	for (const auto &[key, val] : map)
		arr[val].first  = true;
	for (const auto &val : vec)
		arr[val].second = true;

	std::erase_if(map, [&arr](const std::pair<int, int> & el) {
		if (!arr[el.second].first || !arr[el.second].second)
			return true;
		return false;
	});
	std::erase_if(vec, [&arr](const int& el) {
		if (!arr[el].first || !arr[el].second)
			return true;
		return false;
	});
}

void    delete_elems(std::map<int, int> &map, std::vector<int> &vec) {
	std::random_device                  rd;
	std::uniform_int_distribution<int>  dist(0, EL_DEL_);

	size_t num_to_del = dist(rd);
	for (size_t i = 0; i < num_to_del; ++i) {
		map.erase(--map.end());
		vec.erase(--vec.end());
		if (map.empty() || vec.empty())
			break;
	}
}

void    fill_conts(std::map<int, int> &map, std::vector<int> &vec) {
	std::random_device                  rd;
	std::uniform_int_distribution<int>  dist(1, 9);
	std::uniform_int_distribution<int>  create_dist(0, MAX_SIZE_);
	size_t                              size = create_dist(rd);

	if (size == 0) {
		std::cout << "U randomed 0 size, try again!" << std::endl;
		exit(0);
	}
	vec.reserve(size);
	for (int n = 0; n < size; ++n) {
		map[n] = dist(rd);
		vec.push_back(dist(rd));
	}
}

int     main() {
	std::random_device  rd;
	std::map<int, int>  my_map;
	std::vector<int>    my_vec;

	fill_conts(my_map, my_vec);
	std::cout << "Map before erase:    " << my_map << std::endl;
	std::cout << "Vector before erase: " << my_vec << std::endl;
	std::cout << std::endl;

	delete_elems(my_map, my_vec);
	std::cout << "Map after erase:    "  << my_map << std::endl;
	std::cout << "Vector after erase: "  << my_vec << std::endl;
	std::cout << std::endl;

	synchronize(my_map, my_vec);
	std::cout << "Map after sync:    " << my_map << std::endl;
	std::cout << "Vector after sync: " << my_vec << std::endl;
	return 0;
}
