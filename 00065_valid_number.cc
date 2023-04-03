    class State;

    class StateMachine {
    public:
        static State* START;

        static State* MANT_WHOLE_START;
        static State* MANT_WHOLE;
        static State* MANT_FRAC_START;
        static State* MANT_FRAC;


        static State* EXP_START;
        static State* EXP_WHOLE_START;        
        static State* EXP_WHOLE;

        static State* FAILED;
        static State* SUCCESS;


    private:
        State* curState;
        void ProcessChar(char c);

    public:
        StateMachine() : curState(START) {}
        void setState(State* state) { curState = state; }

        bool hasFailed() const { return curState == FAILED; }
        bool hasSucceeded() const { return curState == SUCCESS; }

        void Process(const string& s);
    };

    class State {
    public:
        virtual void ProcessSign(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
        virtual void ProcessDot(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
        virtual void ProcessDigit(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
        virtual void ProcessInvalid(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
        virtual void ProcessExp(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
        virtual void ProcessEos(StateMachine* sm) {
            sm->setState(StateMachine::FAILED);
        }
    };

    class StartState : public State {
        virtual void ProcessSign(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_WHOLE_START);
        }
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_WHOLE);
        }
        virtual void ProcessDot(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_FRAC_START);
        }
    };

    class MantWholeStartState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_WHOLE);
        }
        virtual void ProcessDot(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_FRAC_START);
        }
    };

    class MantWholeState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_WHOLE);
        }
        virtual void ProcessDot(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_FRAC);
        }
        virtual void ProcessExp(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_START);
        }
        virtual void ProcessEos(StateMachine* sm) override {
            sm->setState(StateMachine::SUCCESS);
        }
    };

    class MantFracStartState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_FRAC);
        }
    };

    class MantFracState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::MANT_FRAC);
        }
        virtual void ProcessExp(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_START);
        }
        virtual void ProcessEos(StateMachine* sm) override {
            sm->setState(StateMachine::SUCCESS);
        }
    };

    class ExpStartState : public State {
        virtual void ProcessSign(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_WHOLE_START);
        }
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_WHOLE);
        }
    };

    class ExpWholeStartState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_WHOLE);
        }
    };

    class ExpWholeState : public State {
        virtual void ProcessDigit(StateMachine* sm) override {
            sm->setState(StateMachine::EXP_WHOLE);
        }
        virtual void ProcessEos(StateMachine* sm) override {
            sm->setState(StateMachine::SUCCESS);
        }
    };

    class FailedState : public State {
    };

    class SuccessState : public State {
    };

    State* StateMachine::START = new StartState;

    State* StateMachine::MANT_WHOLE_START = new MantWholeStartState;
    State* StateMachine::MANT_WHOLE = new MantWholeState;

    State* StateMachine::MANT_FRAC_START = new MantFracStartState;
    State* StateMachine::MANT_FRAC = new MantFracState;
 
    State* StateMachine::EXP_START = new ExpStartState;
    State* StateMachine::EXP_WHOLE_START = new ExpWholeStartState;
    State* StateMachine::EXP_WHOLE = new ExpWholeState;

    State* StateMachine::FAILED = new FailedState;
    State* StateMachine::SUCCESS = new SuccessState;

    void StateMachine::ProcessChar(char c) {
        switch (c) {
            case '+':
            case '-':
                curState->ProcessSign(this);
                break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                curState->ProcessDigit(this);
                break;

            case '.':
                curState->ProcessDot(this);
                break;

            case 'e':
            case 'E':
                curState->ProcessExp(this);
                break;

            case '\0':
                curState->ProcessEos(this);
                break;

            default:
                curState->ProcessInvalid(this);
                break;
        }
    }

    void StateMachine::Process(const string& s) {
        for (auto c : s) {
            ProcessChar(c);
            if (hasFailed()) return;
        }
        ProcessChar('\0');
    }

class Solution {
  
public:
    bool isNumber(string s) {
        StateMachine sm;
        sm.Process(s);

        return sm.hasSucceeded();
    }
};
