#ifndef ELEVATOR_HPP_INCLUDED
#define ELEVATOR_HPP_INCLUDED

#include <tinyfsm.hpp>


// ----------------------------------------------------------------------------
// Event declarations
//

struct FloorEvent : tinyfsm::Event
{
  int floor;
};

struct Call        : FloorEvent { };
struct FloorSensor : FloorEvent { };
struct Alarm       : tinyfsm::Event { };



// ----------------------------------------------------------------------------
// Elevator (FSM base class) declaration
//

class Elevator
: public tinyfsm::Fsm<Elevator>
{
  /* NOTE: react(), entry() and exit() functions need to be accessible
   * from tinyfsm::Fsm class. You might as well declare friendship to
   * tinyfsm::Fsm, and make these functions private:
   *
   * friend class Fsm;
   */
public:

  /* default reaction for unwanted events */
  void react(tinyfsm::Event const &) { };

  virtual void react(Call        const &);
  virtual void react(FloorSensor const &);
  virtual void react(Alarm       const &) final;

  virtual void entry(void) { };
  void         exit(void)  { }; /* no exit actions */

protected:

  static int current_floor;
  static int dest_floor;
};


#endif
