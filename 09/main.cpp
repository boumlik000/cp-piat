#include "BitcoinExchange.hpp"

int count_w (std::string line)
{
    int c = 0;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word)
    {
        c++;
    }
    return c;
}

bool check_head_line(std::string line)
{
    if (count_w(line) != 3)
    {
        std::cerr << "Error: this line need to have 3 arguments , first | second (" << line << ")" << std::endl;
        return false;
    }
    std::stringstream ss(line);
    
    std::string first , second , third;
    ss >> first >> second >> third;
    if (first != "date" || second != "|" || third != "value" )
    {
        std::cerr << "Error: headline incorrect format (date | value)" << std::endl;
        return false;
    }
    return true;
}


bool chek_year(std::string first)
{
    // std::cout << first.size() << std::endl;
    const char* s = first.c_str();
    int i = 0;
    if (first.size() != 4)
    {
        std::cout << "Error:  in yearx1 " << first << std::endl;
        return false;  
    }
    if (first[0] != '2')
    {
        std::cout << "Error:  in year " << first << std::endl;
        return false;
    }
    while (s[i])
    {
        if (!isdigit(s[i]))
        {
            std::cerr << "Error: this year input is not int !" << std::endl;
            return false;
        }
        i++;
    }
    int n_year = atoi(s) ;
    if (n_year < 2009 || n_year >= 2023)
    {
       std::cerr << "Error: bad input" << std::endl;
       return false;
    }
    
    return true;
}

bool check_month(std::string first)
{
    // std::cout << first.size() << std::endl;
    const char* s = first.c_str();
    int i = 0;
    if (first.size() != 2)
    {
        std::cout << "Error:  in monthx1 " << first << std::endl;
        return false;  
    }
    while (s[i])
    {
        if (!isdigit(s[i]))
        {
            std::cerr << "Error: this month input is not int !" << std::endl;
            return false;
        }
        i++;
    }
    int n_month = atoi(s) ;
    if (n_month <= 0 || n_month > 12 )
    {
        std::cerr << "Error: the month is out of renge" << std::endl;
        return false;
    }
    return true;
}

bool check_day(std::string first)
{
    // std::cout << first.size() << std::endl;
    const char* s = first.c_str();
    int i = 0;
    if (first.size() != 2)
    {
        std::cout << "Error:  in dayx1 " << first << std::endl;
        return false;  
    }
    while (s[i])
    {
        if (!isdigit(s[i]))
        {
            std::cerr << "Error: this day input is not int !" << std::endl;
            return false;
        }
        i++;
    }
    int n_month = atoi(s) ;
    if (n_month <= 0 || n_month > 31 )
    {
        std::cerr << "Error: the day is out of renge" << std::endl;
        return false;
    }
    return true;
}

bool check_value(std::string first)
{
    // std::cout << first.size() << std::endl;
    const char* s = first.c_str();
    int i = 0;

    while (s[i])
    {
        if (s[0] == '-')
        {
            std::cerr << "Error:  not a positive number." << std::endl;
            // return false;
        }
        if (!isdigit(s[i]))
        {
            std::cerr << "Error: this value input is not int !" << std::endl;
            return false;
        }
        i++;
    }
    return true;
}

bool check_file_lines(std::string line, std::map<std::string, float>& map)
{
    if (count_w(line) != 3)
    {
        std::cerr << "Error: this line need to have 3 arguments , first | third (" << line << ")" << std::endl;
        return false;
    }
    std::stringstream ss(line);
    
    std::string first , second , third;
    ss >> first >> second >> third;

    std::stringstream ff(first);
    std::string n_year_str, n_months_str, n_days_str;

    std::getline(ff, n_year_str, '-');
    std::getline(ff, n_months_str, '-');
    std::getline(ff, n_days_str);

    if (!chek_year(n_year_str) || !check_month(n_months_str) || !check_day(n_days_str))
    {
        std::cerr << "Error:  in formula " << first << std::endl;
        return false;
    }

    if (second != "|")
    {
        std::cerr << "Error:  in formula " << second  << std::endl;
        return false;
    }

    if (!check_value(third))
    {
        std::cerr << "Error:  in formula " << third  << std::endl;
        return false;
    }
    
    float value = atof(third.c_str());
    
    map[first] = value;
    
    return true;
}

int main(int ac, char  *av[])
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "u need to insert a file as an argument" << std::endl;
        return 0;
    }
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cerr << "cant open the file " << std::endl;
        return 0;
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: file is empty" << std::endl;
        return 0;
    }
    std::string line;
    std::getline(file,line);
    if (!check_head_line(line))
    {
        std::cerr << "error in file in " << line << std::endl;
        return 0;
    }
    
    //------------------------- check all the file
    std::map<std::string,float> map1;
    std::map<std::string,float>::iterator it;

    while (std::getline(file,line))
    {
        if(!check_file_lines(line, map1))
        {
            std::cerr << "error in file in " << line << std::endl;
            return 0;
        }
    }
    file.close();
    
    // for (it=map1.begin() ; it != map1.end() ; it++)
    // {
    //     std::cout << it->first <<  " " << it->second << std::endl;
    // }
    

    // second file
    std::ifstream file2("data.csv");
    if (!file2.is_open())
    {
        std::cerr << "cant open the file " << std::endl;
        return 0;
    }
    std::map<std::string,float> map2;
    std::string line0;
    std::map<std::string,float>::iterator it2;
    std::getline(file2,line0);

    while (std::getline(file2,line0))
    {
        std::stringstream pp(line0);
        std::string date, val;
        
        std::getline(pp,date,',');
        std::getline(pp,val);

        float v = atof(val.c_str());
        if (map2.find(date) != map2.end())
        {
            std::cerr << "Error: duplicate date found: " << date << std::endl;
            file2.close();
            return 0;
        }
        map2[date] = v;

    }
    file2.close();
    
    for (it = map1.begin(); it != map1.end(); it++)
    {   
        // Find nearest lower or equal date in map2 (CSV file)
        std::map<std::string, float>::iterator upper = map2.upper_bound(it->first);
        
        if (upper == map2.begin())
        {
            std::cerr << "Error: no price data available for date " << it->first << std::endl;
            continue;
        }
        
        --upper;  // Get the nearest lower or equal date from CSV
        
        std::string csv_date = upper->first;
        float csv_price = upper->second;
        float result = it->second * csv_price;
        // std::cout << result << std::endl;
        if (result > INT_MAX)
        {
            std::cerr << "Error: value is too large for int" << std::endl;
            return 1;
        }
        std::cout << it->first << " => " << csv_date 
                << " | " << it->second << " * " << csv_price 
                << " = " << result << std::endl;
    }

    

    return 0;
}
