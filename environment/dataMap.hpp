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
    DataMap& operator=(DataMap const& other) = delete;
    ~DataMap() = default;

    inline void insert(std::string const& varPath){ m_map.insert(std::pair<std::string,float>(varPath,0.0f));}
    inline void insert(std::string && varPath){ m_map.insert(std::pair<std::string,float>{std::move(varPath),0.0f});}
    //Remember: this function is only used by the server
    inline void set(std::string const& varPath, float value){ m_map.at(varPath) = value;}
    //Remember: this function is only used by the server
    inline void set(std::string && varPath, float value){ m_map.at(std::move(varPath)) = value;}
    inline float get(std::string const& varPath) const { return m_map.at(varPath);}
    inline float get(std::string && varPath) const { return m_map.at(std::move(varPath));}

private:
    std::unordered_map<std::string , std::atomic<float>> m_map;
};

}//namespace fp
}// namespace env

#endif
