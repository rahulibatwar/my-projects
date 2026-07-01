import time
import json
from datetime import datetime

class CentralizedLoggingEngine:
    """Architecting an Enterprise Real-time Logging & Monitoring System"""
    def __init__(self):
        self.log_pipeline = []
        print("🚀 [Monitor] Centralized Logging Pipeline Initialized Successfully.")

    def emit_log(self, subsystem, level, message):
        """Ingesting system telemetry data with precise timestamps"""
        log_payload = {
            "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3],
            "subsystem": subsystem.upper(),
            "level": level.upper(),
            "message": message
        }
        self.log_pipeline.append(log_payload)
        
        # Color coding for terminal visibility
        color = "\033[94m" if level == "INFO" else "\033[93m" if level == "WARN" else "\033[91m"
        reset = "\033[0m"
        print(f"{color}[{log_payload['timestamp']}] [{log_payload['level']}] [{log_payload['subsystem']}] {log_payload['message']}{reset}")

    def run_system_telemetry(self):
        """Simulating live cross-infrastructure traffic logs"""
        print("\n⚡ [Simulation] Starting Infrastructure Microservices Test...")
        print("-" * 75)
        
        # Simulating Thursday API Gateway Telemetry
        self.emit_log("Gateway", "INFO", "Incoming connection from 192.168.1.50 accepted.")
        time.sleep(0.2)
        self.emit_log("Gateway", "WARN", "Rate limit token bucket depleted below 10%.")
        time.sleep(0.3)
        self.emit_log("Gateway", "ERROR", "HTTP 429: Too Many Requests on route /api/v1/userData.")
        
        # Simulating Friday Database Telemetry
        time.sleep(0.4)
        self.emit_log("Database", "INFO", "SQL INNER JOIN query executed on Users & Roles tables.")
        time.sleep(0.2)
        self.emit_log("Database", "ERROR", "Foreign Key integrity constraint violation blocked on entry UID=4.")
        print("-" * 75)

    def generate_incident_report(self):
        """Parsing logs to filter critical exceptions and errors"""
        print("\n📊 [Analytics] Filtering System Incidents (ERROR Level Only)...")
        critical_incidents = [log for log in self.log_pipeline if log["level"] == "ERROR"]
        
        print("=" * 75)
        print(f"🚨 SECURITY REPORT: {len(critical_incidents)} CRITICAL ERRORS DETECTED")
        print("=" * 75)
        for idx, incident in enumerate(critical_incidents, 1):
            print(f"{idx}. [{incident['timestamp']}] Module: {incident['subsystem']} -> {incident['message']}")
        print("=" * 75)

def main():
    # Initialize the analytics dashboard
    monitor = CentralizedLoggingEngine()
    monitor.run_system_telemetry()
    monitor.generate_incident_report()

if __name__ == "__main__":
    main()