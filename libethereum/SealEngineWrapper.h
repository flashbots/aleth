class SealEngineWrapper
{
    SealEngineWrapper(u256 const& reward) : reward(reward) {}

    u256 blockReward(u256 const* blockNumber) { return reward + (blockNumber * 0); }

private:
    u256 reward;
};


