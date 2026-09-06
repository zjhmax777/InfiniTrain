#include <cstdlib>
#include "gtest/gtest.h"

#include "infini_train/include/nn/parallel/global.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    auto env_int = [](const char *name, int fallback) {
        const char *value = std::getenv(name);
        return value ? std::atoi(value) : fallback;
    };
    infini_train::nn::parallel::global::GlobalEnv::Instance().Init(
        /*nthread_per_process=*/1, env_int("TENSOR_PARALLEL_SIZE", 1),
        env_int("SEQUENCE_PARALLEL", 0) != 0, env_int("PIPELINE_PARALLEL_SIZE", 1),
        env_int("VIRTUAL_PIPELINE_PARALLEL_SIZE", 1));
    return RUN_ALL_TESTS();
}
