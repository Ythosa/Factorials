#include "benchmark/benchmark.h"
#include "falgo.h"

static void BM_PrimeSwing(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::PrimeSwing::Count(i);
        }
    }
}

static void BM_SimpleRecursion(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::SimpleRecursion::Count(i);
        }
    }
}

static void BM_SimpleWhile(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::SimpleWhile::Count(i);
        }
    }
}

static void BM_TakingFromArray(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::TakingFromArray::Count(i);
        }
    }
}

static void BM_Tree(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::Tree::Count(i);
        }
    }
}

static void BM_FactFactor(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::FactFactor::Count(i);
        }
    }
}

static void BM_FactFast(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::FactFast::Count(i);
        }
    }
}

static void BM_FactNaive(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::FactNaive::Count(i);
        }
    }
}

static void BM_SimpleFactNaive(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::SimpleFactNaive::Count(i);
        }
    }
}

static void BM_InitAndTakeFromArray(benchmark::State& state) {
    for (auto _ : state) {
        for (long long i = 0; i < 21; i++) {
            falgo::InitAndTakeFromArray::Count(i);
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_PrimeSwing);
BENCHMARK(BM_SimpleRecursion);
BENCHMARK(BM_SimpleWhile);
BENCHMARK(BM_TakingFromArray);
BENCHMARK(BM_Tree);
BENCHMARK(BM_FactFactor);
BENCHMARK(BM_FactFast);
BENCHMARK(BM_FactNaive);
BENCHMARK(BM_SimpleFactNaive);
BENCHMARK(BM_InitAndTakeFromArray);

// Run the benchmark
BENCHMARK_MAIN();
