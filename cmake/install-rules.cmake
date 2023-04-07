install(
    TARGETS connect-four_exe
    RUNTIME COMPONENT connect-four_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
