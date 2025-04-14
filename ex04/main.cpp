/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:36:38 by joklein           #+#    #+#             */
/*   Updated: 2025/04/14 16:23:18 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fstream>
# include <iostream>
# include <string>

std::string repalce_input(std::string line, int i, int u, char **argv)
{
	std::string line_new = line.substr(0, i - u);
	line_new += argv[3];
	line_new += line.substr(i);
	return (line_new);
}

int	main(int argc, char **argv)
{
	int	u;
	int	i_temp;

	std::string line;
	if (argc != 4)
		return (std::cout << "wrong number of arguments" << std::endl, 1);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		return (std::cout << "wrong input" << std::endl, 1);
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cout << "wrong file" << std::endl;
		return (1);
	}
	std::string in_file_name = argv[1];
    std::string replace_arg = argv[3];
	std::string out_file_name = in_file_name + ".replace";
	std::ofstream out_file(out_file_name);
	if (!out_file)
	{
		std::cerr << "could not open file" << std::endl;
		return (1);
	}
	while (std::getline(file, line))
	{
		for (int i = 0; line[i]; i++)
		{
			u = 0;
			i_temp = i;
			while (line[i] == argv[2][u])
			{
				i++;
				u++;
			}
			if (argv[2][u] == '\0')
			{
				line = repalce_input(line, i, u, argv);
				i = i_temp + replace_arg.length();
			}
		}
		out_file << line << std::endl;
	}
	file.close();
	out_file.close();
}
