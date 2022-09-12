#include <iostream>
#include <vector>

//def
class matrixMethod
{
    public:
        template <class T>
        static void Matrix_generation(std::vector< std::vector<T> > &matrix)
        {
            int m, n;
            std::cin >> m;
            std::cin >> n;
            matrix.resize(m , std::vector<T>(n));
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    std::cin >> matrix[i][j];
                }
            }
            return;
        }
        /*
        input:
        m (rows)
        n (columns)
        matrix info
        */
        template <class T>
        static void printMatrix(std::vector<std::vector<T>>& matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();

            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << "\n";
            }
            return;
        }
};

class vectorMethod
{
    public:
        template <class T>
        static void Vector_generation(std::vector<T> &arr)
        {
            int m;
            std::cin >> m;
            arr.resize(m);
            for(int i = 0; i < m; ++i)
            {
                std::cin >> arr[i];
            }
            return;
        }

        template <class T>
        static void printVector(std::vector<T> &arr)
        {
            for(auto &i : arr)
            {
                std::cout<< i << " ";
            }
            std::cout<<"\n";
        }
};


void include_test()
{
    std::cout << "Matrix.hpp is included.\n";
    return;
}

