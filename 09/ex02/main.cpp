#include "PmergeMe.hpp"



// Global comparison counters
static size_t g_comparisons_vector = 0;
static size_t g_comparisons_deque = 0;

// Get time in microseconds
double getTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

bool check_av(char *av)
{
    int i = 0;
    
    if (!av[i])
        return false;
    
    if (av[i] == '+')
        i++;
    
    if (!av[i])
        return false;
    
    while (av[i])
    {
        if (!isdigit(av[i]))
        {
            std::cout << av << " is not a digit" << std::endl;
            return false;
        }
        i++;
    }
    
    long num = atol(av);
    if (num > INT_MAX || num < 0)
    {
        std::cout << av << " is out of range" << std::endl;
        return false;
    }
    
    return true;
}

// Binary search insertion for vector
int binarySearchInsert(std::vector<int>& arr, int item, int end)
{
    int left = 0;
    int right = end;
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        g_comparisons_vector++; // Count comparison
        if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Binary search insertion for deque
int binarySearchInsertDeque(std::deque<int>& arr, int item, int end)
{
    int left = 0;
    int right = end;
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        g_comparisons_deque++; // Count comparison
        if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Generate Jacobsthal numbers for insertion order
std::vector<size_t> generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    if (n > 0) jacobsthal.push_back(1);
    
    size_t i = 2;
    while (true)
    {
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next >= n)
            break;
        jacobsthal.push_back(next);
        i++;
    }
    
    return jacobsthal;
}

std::vector<size_t> getInsertionOrder(size_t pendSize)
{
    std::vector<size_t> order;
    if (pendSize == 0)
        return order;
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendSize);
    std::vector<bool> used(pendSize, false);
    
    // Insert elements according to Jacobsthal sequence
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        size_t pos = jacobsthal[i];
        if (pos < pendSize)
        {
            // Insert from jacobsthal[i] down to jacobsthal[i-1] + 1
            for (size_t j = pos; j > jacobsthal[i-1] && j < pendSize; j--)
            {
                if (!used[j])
                {
                    order.push_back(j);
                    used[j] = true;
                }
            }
        }
    }
    
    // Insert remaining elements
    for (size_t i = 0; i < pendSize; i++)
    {
        if (!used[i])
            order.push_back(i);
    }
    
    return order;
}

std::vector<int> fordJohnsonSort(std::vector<int>& arr)
{
    // Base case
    if (arr.size() <= 1)
        return arr;
    
    // Step 1 & 2: Group into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        g_comparisons_vector++; // Count comparison for pair sorting
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    
    if (arr.size() % 2 != 0)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }
    
    // Step 3: Separate into main chain (s) and pend chain
    std::vector<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);  // larger elements
        pend.push_back(pairs[i].second);       // smaller elements
    }
    
    // --- START OF OPTIMIZATION ---

    // Step 4: Recursively sort the main chain
    std::vector<int> mainChainCopy = mainChain; // 1. Store original mainChain
    std::vector<int> sortedMainChain;

    if (mainChain.size() > 1)
        sortedMainChain = fordJohnsonSort(mainChain); // 2. Recursive call
    else
        sortedMainChain = mainChain; // Base case

    // 3. Create orderedPend by re-linking (O(n^2) but no comparisons)
    std::vector<int> orderedPend;
    for (size_t i = 0; i < sortedMainChain.size(); i++)
    {
        int sortedValue = sortedMainChain[i];
        for (size_t j = 0; j < mainChainCopy.size(); j++)
        {
            if (mainChainCopy[j] == sortedValue)
            {
                orderedPend.push_back(pend[j]); // 4. Add corresponding pend element
                break;
            }
        }
    }

    // Step 5: Insert first pend element
    std::vector<int> result;
    if (!orderedPend.empty())
    {
        result.push_back(orderedPend[0]); // Use orderedPend[0]
    }
    
    // Add all main chain elements
    for (size_t i = 0; i < sortedMainChain.size(); i++)
    {
        result.push_back(sortedMainChain[i]);
    }
    
    // Step 6: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> insertionOrder = getInsertionOrder(orderedPend.size());
    
    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t idx = insertionOrder[i];
        if (idx > 0 && idx < orderedPend.size()) // Skip first one
        {
            int itemToInsert = orderedPend[idx];
            int upperBoundValue = sortedMainChain[idx]; // The pair!

            // Find where the pair is in the current result
            std::vector<int>::iterator it;
            it = std::lower_bound(result.begin(), result.end(), upperBoundValue);
            
            // Convert iterator to position
            int upperBoundPos = std::distance(result.begin(), it);

            // Search only up to that position
            int pos = binarySearchInsert(result, itemToInsert, upperBoundPos);
            
            result.insert(result.begin() + pos, itemToInsert);
        }
    }
    
    // --- END OF OPTIMIZATION ---

    // Last step: Insert straggler if exists
    if (hasStraggler)
    {
        int pos = binarySearchInsert(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
    }
    
    return result;
}

// Ford-Johnson sort for deque
std::deque<int> fordJohnsonSortDeque(std::deque<int>& arr)
{
    // Base case
    if (arr.size() <= 1)
        return arr;
    
    // Step 1 & 2: Group into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        g_comparisons_deque++; // Count comparison for pair sorting
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    
    if (arr.size() % 2 != 0)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }
    
    // Step 3: Separate into main chain (s) and pend chain
    std::deque<int> mainChain;
    std::deque<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);  // larger elements
        pend.push_back(pairs[i].second);       // smaller elements
    }
    
    // --- START OF OPTIMIZATION ---

    // Step 4: Recursively sort the main chain
    std::deque<int> mainChainCopy = mainChain; // 1. Store original mainChain
    std::deque<int> sortedMainChain;

    if (mainChain.size() > 1)
        sortedMainChain = fordJohnsonSortDeque(mainChain); // 2. Recursive call
    else
        sortedMainChain = mainChain; // Base case

    // 3. Create orderedPend by re-linking
    std::deque<int> orderedPend;
    for (size_t i = 0; i < sortedMainChain.size(); i++)
    {
        int sortedValue = sortedMainChain[i];
        for (size_t j = 0; j < mainChainCopy.size(); j++)
        {
            if (mainChainCopy[j] == sortedValue)
            {
                orderedPend.push_back(pend[j]); // 4. Add corresponding pend element
                break;
            }
        }
    }

    // Step 5: Insert first pend element
    std::deque<int> result;
    if (!orderedPend.empty())
    {
        result.push_back(orderedPend[0]); // Use orderedPend[0]
    }
    
    // Add all main chain elements
    for (size_t i = 0; i < sortedMainChain.size(); i++)
    {
        result.push_back(sortedMainChain[i]);
    }
    
    // Step 6: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> insertionOrder = getInsertionOrder(orderedPend.size());
    
    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t idx = insertionOrder[i];
        if (idx > 0 && idx < orderedPend.size()) // Skip first one
        {
            int itemToInsert = orderedPend[idx];
            int upperBoundValue = sortedMainChain[idx]; // The pair!

            // Find where the pair is in the current result
            std::deque<int>::iterator it;
            it = std::lower_bound(result.begin(), result.end(), upperBoundValue);
            
            // Convert iterator to position
            int upperBoundPos = std::distance(result.begin(), it);

            // Search only up to that position
            int pos = binarySearchInsertDeque(result, itemToInsert, upperBoundPos);
            
            result.insert(result.begin() + pos, itemToInsert);
        }
    }

    // --- END OF OPTIMIZATION ---

    // Last step: Insert straggler if exists
    if (hasStraggler)
    {
        int pos = binarySearchInsertDeque(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
    }
    
    return result;
}

int main(int ac, char *av[])
{
    if (ac == 1)
    {
        std::cerr << "Error: please enter arguments" << std::endl;
        return 1;
    }
    
    std::vector<int> vect;
    std::deque<int> deq;
    
    for (int i = 1; i < ac; i++)
    {
        if (!check_av(av[i]))
        {
            std::cerr << "Error: wrong input, only positive numbers" << std::endl;
            return 1;
        }
        int x = atoi(av[i]);
        if (std::find(vect.begin(), vect.end(), x) != vect.end())
        {
            std::cerr << "Error: duplicate number found (" << x << ")" << std::endl;
            return 1;
        }
        vect.push_back(x);
        deq.push_back(x);
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i];
        if (i < vect.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    // ===== VECTOR SORTING =====
    g_comparisons_vector = 0;
    
    double startTimeVector = getTimeInMicroseconds();
    std::vector<int> sortedVector = fordJohnsonSort(vect);
    double endTimeVector = getTimeInMicroseconds();
    double durationVector = endTimeVector - startTimeVector;
    
    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVector.size(); i++)
    {
        std::cout << sortedVector[i];
        if (i < sortedVector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl; 
    
    std::cout << "Time to process a range of " << vect.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) 
              << durationVector << " us" << std::endl;
    std::cout << "Number of comparisons (vector): " << g_comparisons_vector << std::endl;
    
    // ===== DEQUE SORTING =====
    g_comparisons_deque = 0;
    
    double startTimeDeque = getTimeInMicroseconds();
    std::deque<int> sortedDeque = fordJohnsonSortDeque(deq);
    double endTimeDeque = getTimeInMicroseconds();
    double durationDeque = endTimeDeque - startTimeDeque;
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " 
              << std::fixed << std::setprecision(5) 
              << durationDeque << " us" << std::endl;
    
    std::cout << "Number of comparisons (deque): " << g_comparisons_deque << std::endl;
    
    // Calculate theoretical minimum (for reference)
    size_t n = vect.size();
    if (n > 1)
    {
        double theoreticalMin = n * log2(n) - n * log2(2.718281828) + n;
        std::cout << "\nTheoretical minimum comparisons: ~" 
                  << static_cast<size_t>(theoreticalMin) << std::endl;
    }
    
    return 0;
}