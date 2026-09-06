# ==========================================================================
# Pipeline layout tests
# ==========================================================================

infini_train_add_test(test_pipeline_layout_cpu
  SOURCES test_pipeline_layout.cc
  LABELS cpu
)

infini_train_add_test(test_pipeline_scheduler_layout_cpu
  SOURCES test_pipeline_scheduler_layout.cc
  LABELS cpu
)

infini_train_add_test(test_pipeline_parallel_chunking_cpu
  SOURCES test_pipeline_parallel_chunking.cc
  LABELS cpu
)
