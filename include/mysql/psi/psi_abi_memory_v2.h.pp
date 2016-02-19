#include "mysql/psi/psi_memory.h"
#include "my_global.h"
#include "psi_base.h"
typedef unsigned int PSI_mutex_key;
typedef unsigned int PSI_rwlock_key;
typedef unsigned int PSI_cond_key;
typedef unsigned int PSI_thread_key;
typedef unsigned int PSI_file_key;
typedef unsigned int PSI_stage_key;
typedef unsigned int PSI_statement_key;
typedef unsigned int PSI_socket_key;
typedef unsigned int PSI_memory_key;
struct PSI_placeholder
{
  int m_placeholder;
};
C_MODE_START
struct PSI_thread;
struct PSI_memory_bootstrap
{
  void* (*get_interface)(int version);
};
typedef struct PSI_memory_bootstrap PSI_memory_bootstrap;
typedef struct PSI_placeholder PSI_memory_service_t;
typedef struct PSI_placeholder PSI_memory_info;
extern MYSQL_PLUGIN_IMPORT PSI_memory_service_t *psi_memory_service;
C_MODE_END