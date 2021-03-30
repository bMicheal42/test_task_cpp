#ifndef UTILS_HPP
# define UTILS_HPP

# include <random>
# include <iostream>
# include <iomanip>
# include <vector>
# include <string>
# include <map>

template <typename Key, typename Type>
std::ostream &operator <<(std::ostream &out, const std::map<Key, Type> &map) {
	for (const auto &p : map) {
		out << "[" << p.first << "] = ";
		out << p.second << "  ";
	}
	out << std::endl;
	return out;
}

template <typename Type>
std::ostream &operator <<(std::ostream &out, const std::vector<Type> &vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		out << "    " << vec[i] << "    ";
	}
	out << std::endl;
	return out;
}

#endif
