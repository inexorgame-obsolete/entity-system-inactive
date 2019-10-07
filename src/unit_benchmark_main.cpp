#include <benchmark/benchmark.h>

/// Windows-specific code.
/// The shlwapi library (-lshlwapi) is required to support a call to CPUInfo which reads the registry.
/// https://github.com/google/benchmark
#ifdef _WIN32
   #include <Shlwapi.h>
   #pragma comment(lib, "Shlwapi.lib")
#endif


// This is an example benchmark.
static void ExampleBenchmark(benchmark::State& state)
{
	for (auto _ : state)
	{
		std::string str = "Hello World";
	}
}

BENCHMARK(ExampleBenchmark);

BENCHMARK_MAIN();
