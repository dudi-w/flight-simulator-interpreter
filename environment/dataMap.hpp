#ifndef DATA_MAP_HPP
#define DATA_MAP_HPP

#include <unordered_map>
#include <atomic>
#include <string>

namespace fp { // namespace flight plan
namespace env { // namespace env

class DataMap
{
public:
    DataMap() = default;
    DataMap(DataMap const& other) = default;
    DataMap& operator=(DataMap const& other) = default;
    ~DataMap() = default;

    inline void insert(std::string const& varPath){ m_map.insert({varPath,0});}
    inline void insert(std::string && varPath){ m_map.insert({std::move(varPath),0});}
    //Remember: this function is only used by the server
    inline void set(std::string const& varPath, float value){ m_map.at(varPath) = value;}
    //Remember: this function is only used by the server
    inline void set(std::string && varPath, float value){ m_map.at(std::move(varPath)) = value;}
    inline float get(std::string const& varPath){ return m_map.at(varPath);}
    inline float get(std::string && varPath){ return m_map.at(std::move(varPath));}

private:
    std::unordered_map<std::string , std::atomic<float>> m_map;
};

}//namespace fp
}// namespace env

#endif
