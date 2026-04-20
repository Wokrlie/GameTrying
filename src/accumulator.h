class Accumulator {
    public:
        Accumulator() { m_accumulator = 0.0f; };

        void AddAccumulator(float time) { m_accumulator += time; }
        void MinusAccumulator(float time) { m_accumulator -= time; }
        float GetAccumulator() { return m_accumulator; }
        
    private:
        float m_accumulator;
};
