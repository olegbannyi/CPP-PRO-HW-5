# CPP PRO: Home Work \#5

## Build and run

### Thread unsafe version

Build and run thread unsafe version

```bash
$ make all-unsafe
```

### Thread safe version

Build and run thread safe version

```bash
$ make all-safe
```

## Input parameters

```
Initial account balance: 1000.00
Number of cachiers: 5
Number of tranaction per cachier: 100
Random deposit amount: 50.00 - 500.00
Random withdraw amount: 10.00 - 200.00
```

## Example of results

### Thread unsafe version

```
=== Bank Simulation Results ===
Initial balance: 1000.00
Final balance: 92388.21
Total transactions: 1086
Total transaction amount: 206988.06
All cashiers completed work unsafely!
```
Transaction records are saved in log files.
```
build/unsafe/cachier-{1..5}.log
```
