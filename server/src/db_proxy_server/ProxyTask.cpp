#include "ProxyTask.h"
#include "ProxyConn.h"

CProxyTask::CProxyTask(uint32_t conn_uuid, pdu_handler_t pdu_handler, CImPdu *pPdu)
{
  m_conn_uuid = conn_uuid;
  m_pdu_handler = pdu_handler;
  m_pPdu = pPdu;
}

CProxyTask::~CProxyTask()
{
  if (m_pPdu)
  {
    delete m_pPdu;
  }
}

void CProxyTask::run()
{
  if (!m_pPdu)
  {
    // tell CProxyConn to close connection with m_conn_uuid
    CProxyConn::AddResponsePdu(m_conn_uuid, NULL);
  }
  else
  {
    if (m_pdu_handler)
    {
      m_pdu_handler(m_pPdu, m_conn_uuid);
    }
  }
}
