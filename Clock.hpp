#ifndef SFML_CLOCK_HPP
#define SFML_CLOCK_HPP

#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>


namespace sf
{
class SFML_SYSTEM_API Clock
{
public:

   Clock();

   Time getElapsedTime() const;

   Time restart();

private:

   // Member data
   Time m_startTime;
};

} // namespace sf


#endif // SFML_CLOCK_HPP
