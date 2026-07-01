# Enterprise Backend Architecture Suite

A robust, production-ready microservices backend infrastructure built using Python. This suite showcases core system design principles, secure database relational mapping, and centralized observability.

## 🚀 Architecture Components

### 1. API Gateway & Traffic Shaper (Rate Limiter)
*   **File:** `thursday_api_gateway.py`
*   **Mechanism:** Token Bucket Algorithm.
*   **Functionality:** Limits high-speed burst traffic to protect backend resources. Dynamically tracks IP addresses, manages token depletion, and enforces strict `HTTP 429 Too Many Requests` status codes when limits are breached.

### 2. Relational Database Layer & SQL Joins
*   **File:** `friday_db_architect.py`
*   **Mechanism:** Relational Database Schema with Foreign Key Constraints.
*   **Functionality:** Simulates an enterprise user-role permission system. Utilizes structured `SQL INNER JOIN` operations to dynamically aggregate user credentials with assigned security access levels.

### 3. Centralized Log Analyzer Engine
*   **File:** `saturday_log_engine.py`
*   **Mechanism:** System Telemetry Pipeline.
*   **Functionality:** Consolidates real-time tracking logs across all microservices. Features automated log-level parsing (`INFO`, `WARN`, `ERROR`) and dynamically generates Security Incident Reports highlighting critical infrastructure events.

---
*Developed as part of advanced computer science architecture and system design engineering modules.*