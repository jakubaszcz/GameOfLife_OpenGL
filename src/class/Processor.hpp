#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

class Processor {
  protected:
    bool programQuit = false;
    bool isSimulation = false;
  public:
    Processor() = default;
    void QuitProgram();
    bool _ExitProgram() { return programQuit; };
    bool _SimulationProgram() { return isSimulation; };
    void OnProgramQuit() { programQuit = true; }
    void ToggleSimulation() { isSimulation = !isSimulation; };
    void Simulation();
};

#endif //PROCESSOR_HPP
